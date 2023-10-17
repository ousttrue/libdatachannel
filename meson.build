project(
    'libdatachannel',
    ['c', 'cpp'],
    default_options: [
        'cpp_std=c++17',
    ],
)

datachannel_inc = include_directories('include')
subdir('src')
datachannel_dep = declare_dependency(
    include_directories: datachannel_inc,
    link_with: datachannel_lib,
    compile_args: datachannel_args,
)

subdir('examples/copy-paste')

