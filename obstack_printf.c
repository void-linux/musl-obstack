#include <stdarg.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "obstack.h"

int obstack_printf(struct obstack *obstack, const char *__restrict fmt, ...)
{
	va_list ap;
	int len;

	va_start(ap, fmt);
	len = obstack_vprintf(obstack, fmt, ap);
	va_end(ap);

	return len;
}


int obstack_vprintf (struct obstack *obstack, const char *__restrict fmt, va_list args)
{
	char buf[1024];
	size_t len;
	char * str = buf;

	len = vsnprintf (buf, sizeof(buf), fmt, args);
	if (len >= sizeof(buf)) {
		str = NULL;
		len = vasprintf(&str, fmt, args);
		if (len < 0) {
			free(str);
			return -1;
		}
	}
	obstack_grow (obstack, str, len);

	if (str != buf)
		free(str);

	return len;
}
