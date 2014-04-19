#include <Sinbyen.h>
#include <autonomon.h>
#include <speech.h>

inherit Sinbyen_Monster("Crimson_Guard");

void guard_create() {
    set_weapon_class(10, Limb_Type_Hand, ({"crushing", "force" }));
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
    init_command("wear all");
}

void configure() {
    ::configure();
    set_title("of the crimson guard");
    add_obey("SINBYEN_LEADER");
    set_chat(5, ({
        ";scan the area",
        "nod at %p",
        "say Good day. to %p",
        ";glance around",
    }));
}

void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
                call_out("guard_create", 2);
}
