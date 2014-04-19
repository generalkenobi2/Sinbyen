#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");


internal int suppression_messages_time;

mixed sinbyen_church_can_attack_in(mapping args) {
        if(suppression_messages_time <= time())
                return ({
                        0, ({ "feel", 0 }), 'a',
                        ([
                                Message_Content     : ({
                                        "majestic",
                                }),
                                Message_Senses      : Message_Sense_Spiritual,
                        ]),
                        "force acting to suppress", ({ 'r', 0, "aggression" }),
                });
        return False;
}

void sinbyen_church_fail_attack_in(mapping args) {
        if(suppression_messages_time <= time()) {
                object def = args["defender"];
                if(def)
                        def->display(([
                                Message_Content : ({
                                        0, ({ "feel", 0 }), "as if some force is watching over", ({ 'o', 0 }),
                                }),
                                Message_Senses  : Message_Sense_Spiritual,
                        ]));
                suppression_messages_time = time() + 5;
        }
        return False;
}

void configure() {
	Map_Base::configure();
	set_short("a church altar");
	add_exit(Direction_South);
	add_exit(Direction_East);
	add_exit(Direction_West);
    add_hook(Can_Attack_In, #'sinbyen_church_can_attack_in);
    add_hook(Fail_Attack_In, #'sinbyen_church_fail_attack_in);
    add_description(({
        "near the altar in a small church",
    }));
    set_contents(([
        Sinbyen_Misc("church_altar") : 1,
    ]));
    
}
