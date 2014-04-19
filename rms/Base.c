#include <Sinbyen.h>
#include <room.h>

inherit "/std/room";

void configure() {
    ::configure();
    add_realm("Sinbyen");
}
