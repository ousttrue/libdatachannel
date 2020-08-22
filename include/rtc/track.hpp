/**
 * Copyright (c) 2020 Paul-Louis Ageneau
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef RTC_TRACK_H
#define RTC_TRACK_H

#include "channel.hpp"
#include "include.hpp"
#include "message.hpp"
#include "queue.hpp"

#include <atomic>
#include <variant>

namespace rtc {

class PeerConnection;
class DtlsSrtpTransport;

class Track final : public std::enable_shared_from_this<Track>, public Channel {
public:
	Track(string mid, std::shared_ptr<DtlsSrtpTransport> transport = nullptr);
	~Track() = default;

	string mid() const;

	void close(void) override;
	bool send(message_variant data) override;
	bool send(const byte *data, size_t size);

	bool isOpen(void) const override;
	bool isClosed(void) const override;
	size_t maxMessageSize() const override;

	// Extended API
	size_t availableAmount() const override;
	std::optional<message_variant> receive() override;

private:
	void open(std::shared_ptr<DtlsSrtpTransport> transport);
	bool outgoing(message_ptr message);
	void incoming(message_ptr message);

	const string mMid;
	std::weak_ptr<DtlsSrtpTransport> mDtlsSrtpTransport;
	std::atomic<bool> mIsClosed = false;

	Queue<message_ptr> mRecvQueue;

	friend class PeerConnection;
};

} // namespace rtc

#endif
