/*
** Test with
**		BUFFER_SIZE = 6
** to test the remaning string condition
*/
char *line;
int		out;
int		p[2];

line = malloc(99999);
out = dup(1);
pipe(p);
dup2(p[1], 1);
write(1, "\naaa\nbbb\n", 12);
dup2(out, 1);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, ""), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "aaa"), 0);
get_next_line(p[0], &line);
UT_ASSERT_EQ(strcmp(line, "bbb"), 0);
