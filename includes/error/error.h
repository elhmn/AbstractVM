#ifndef ERROR_H
# define ERROR_H


#define ERROR(x)	error((x), __FILE__, __LINE__)

void				error(const char *msg = 0,
								const char *file = 0, int line = 0);

#endif
