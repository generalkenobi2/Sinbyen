#include <item.h>
#include <Sinbyen.h>

inherit Sinbyen_Misc("Safe");

internal int matches;

varargs void vault_open(status from_twin) {
    set_open(True);
    if(!from_twin)
        query_twin()->vault_open(True);
}

varargs void vault_close(status from_twin) {
    set_closed(True);
    if(!from_twin)
        query_twin()->vault_close(True);
}

void configure() {
    ::configure();
    set_twin(Sinbyen_Room("map_-2_-7_0")->load()->query_door_object("east"));
}
