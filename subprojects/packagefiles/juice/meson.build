project('libjuice', 'c', version: '1.3.1')
juece_args = ['-DJUICE_STATIC']
juece_inc = include_directories('include')
juece_lib = static_library(
    'juice',
    [
        'src/addr.c',
        'src/agent.c',
        'src/crc32.c',
        'src/const_time.c',
        'src/conn.c',
        'src/conn_poll.c',
        'src/conn_thread.c',
        'src/conn_mux.c',
        'src/base64.c',
        'src/hash.c',
        'src/hmac.c',
        'src/ice.c',
        'src/juice.c',
        'src/log.c',
        'src/random.c',
        'src/server.c',
        'src/stun.c',
        'src/timestamp.c',
        'src/turn.c',
        'src/udp.c',
    ],
    include_directories: [
        juece_inc,
        include_directories('include/juice'),
    ],
    c_args: juece_args + [
        # '-DJUICE_EXPORTS',
    ],
)
juice_dep = declare_dependency(
    include_directories: juece_inc,
    link_with: juece_lib,
    compile_args: juece_args,
)
