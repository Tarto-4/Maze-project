#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#define MAP_HEIGHT 8
#define MAP_WIDTH 8

extern int map[MAP_HEIGHT][MAP_WIDTH]; // Change to int to match the source file

void parse_map(const char *filename);

#endif // MAP_PARSER_H
