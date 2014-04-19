#include <item.h>
#include <Sinbyen.h>

inherit Sinbyen_Misc("Safe");

internal int matches;

varargs void vault_open(status from_twin) {
    set_locked(False, True);
    set_open(True);
    if(!from_twin)
        query_twin()->vault_open(True);
    matches = 0;
}


varargs void vault_close(status from_twin) {
    set_closed(True);
    set_locked(True, True);
    if(!from_twin)
        query_twin()->vault_close(True);
}


void configure() {
    ::configure();
		set_twin(Sinbyen_Room("map_-1_-7_0")->load()->query_door_object("west"));
}

void reset() {
    ::reset();
    if(query_open())
        vault_close();
    if(matches)
        matches = 0;
}
