project('musl-obstack', 'c',
	version: '1.2.3',
	default_options: 'default_library=both')

obstack_source = files([
	'obstack.c',
	'obstack_printf.c',
])

install_headers('obstack.h')

conf_data = configuration_data()

cc = meson.get_compiler('c')

#conf_data.set('HAVE_CONFIG_H', true)

# check_header
conf_data.set('HAVE_STDDEF_H', cc.has_header('stddef.h'))
conf_data.set('HAVE_STDIO_H', cc.has_header('stdio.h'))
conf_data.set('HAVE_STDINT_H', cc.has_header('stdint.h'))
conf_data.set('HAVE_INTTYPES_H', cc.has_header('inttypes.h'))


configure_file(output : 'config.h',
               configuration : conf_data)

add_project_arguments('-DHAVE_CONFIG_H=1', language : 'c')

obstacklib = library('obstack',
	obstack_source,
	include_directories : '.',
	install : true
)

# musl-obstack.pc
pkg = import('pkgconfig')
pkg.generate(obstacklib,
  name: 'musl-obstack',
  filebase: 'musl-obstack',
  description: 'Implementation of obstack functions for musl libc',
  version: meson.project_version())
