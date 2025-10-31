#include "node.hpp"

Vector2 Node::get_center() { return Vector2 { position.x + (size.x / 2), position.y + (size.y / 2) }; }

Node::Node(int x, int y, int w, int h, Color color, const char *symbol): position(Vector2 { .x = (float)x, .y = (float)y } ), size(Vector2 { .x = (float)h, .y = (float)h}), color(color), symbol(symbol) {}

void Node::Draw() {
    Vector2 center = get_center();
    DrawRectangleV(position, size, color);
    DrawText(symbol, center.x, center.y, 12, BLACK);
}
