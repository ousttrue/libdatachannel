project(
    'libdatachannel',
    ['c', 'cpp'],
    default_options: [
        'cpp_std=c++17',
    ],
)

rtc_args = [
    '-DRTC_STATIC',
]
rtc_inc = include_directories('include')
rtc_lib = static_library(
    'rtc',
    [
        'src/candidate.cpp',
        'src/channel.cpp',
        'src/configuration.cpp',
        'src/datachannel.cpp',
        'src/description.cpp',
        'src/global.cpp',
        'src/message.cpp',
        'src/peerconnection.cpp',
        'src/rtcpreceivingsession.cpp',
        'src/track.cpp',
        'src/websocket.cpp',
        'src/websocketserver.cpp',
        'src/rtppacketizationconfig.cpp',
        'src/rtcpsrreporter.cpp',
        'src/rtppacketizer.cpp',
        'src/opusrtppacketizer.cpp',
        'src/opuspacketizationhandler.cpp',
        'src/h264rtppacketizer.cpp',
        'src/nalunit.cpp',
        'src/h264packetizationhandler.cpp',
        'src/av1rtppacketizer.cpp',
        'src/av1packetizationhandler.cpp',
        'src/mediachainablehandler.cpp',
        'src/mediahandlerelement.cpp',
        'src/mediahandlerrootelement.cpp',
        'src/rtcpnackresponder.cpp',
        'src/rtp.cpp',
        'src/capi.cpp',
        'src/impl/certificate.cpp',
        'src/impl/channel.cpp',
        'src/impl/datachannel.cpp',
        'src/impl/dtlssrtptransport.cpp',
        'src/impl/dtlstransport.cpp',
        'src/impl/icetransport.cpp',
        'src/impl/init.cpp',
        'src/impl/peerconnection.cpp',
        'src/impl/logcounter.cpp',
        'src/impl/sctptransport.cpp',
        'src/impl/threadpool.cpp',
        'src/impl/tls.cpp',
        'src/impl/track.cpp',
        'src/impl/utils.cpp',
        'src/impl/processor.cpp',
        'src/impl/sha.cpp',
        'src/impl/pollinterrupter.cpp',
        'src/impl/pollservice.cpp',
        'src/impl/http.cpp',
        'src/impl/httpproxytransport.cpp',
        'src/impl/tcpserver.cpp',
        'src/impl/tcptransport.cpp',
        'src/impl/tlstransport.cpp',
        'src/impl/transport.cpp',
        'src/impl/verifiedtlstransport.cpp',
        'src/impl/websocket.cpp',
        'src/impl/websocketserver.cpp',
        'src/impl/wstransport.cpp',
        'src/impl/wshandshake.cpp',
    ],
    include_directories: [rtc_inc, include_directories('src', 'include/rtc')],
    dependencies: [
        dependency('plog'),
        dependency('juice', default_options: ['default_library=static']),
        dependency(
            'usrsctp',
            default_options: [
                'default_library=static',
                'sctp_build_programs=false',
            ],
        ),
        dependency('libsrtp2', default_options: ['default_library=static']),
        dependency('openssl', default_options: ['default_library=static']),
    ],
    cpp_args: [
        rtc_args,
        '-DRTC_EXPORTS',
        '-DNOMINMAX',
    ],
)

rtc_dep = declare_dependency(
    include_directories: rtc_inc,
    link_with: rtc_lib,
    compile_args: rtc_args,
)

subdir('examples/copy-paste')

