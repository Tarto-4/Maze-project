#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
	float x;
	float y;
	float angle;
	// Add other player attributes here
} Player;

extern Player player; // Declare player as an external variable

#endif // PLAYER_H