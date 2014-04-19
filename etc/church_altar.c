#include <Pantarchic_Church.h>
#include <room.h>
#include <traits.h>
#include <item.h>
#include <interval.h>
#include <locations.h>
#include <services_bounty.h>
#include <Sinbyen.h>

inherit "/std/item";

void init() {
        ::init();
        if(this_player() && query_object_nearby(this_player())) {
                add_action("pray_command", "pray");
                add_action("pray_command", "worship");
        }
}

status pray_command(string arg) {
        object who = this_player();
        unless(arg)
                return notify_fail("Pray for what?");
        object srv = find_object(Sinbyen_NPC("cartwin")); 
        if(!query_object_nearby(srv)) 
            return notify_fail("Nothing happens.");
        if(who->any_hook(At_Deity_Worship))
                who->check_hook(At_Deity_Worship, ([
                        "who"       : who,
                        "deity"     : "Yehovah",
                ]));
        int lives;
        if(arg && sscanf(arg, "grant me %d lives", lives) || sscanf(arg, "grant me %d life", lives)) {
                who->message(({ 0, ({ "pray", 0 }), "to be granted", numerical(lives), "lives" }));
                if(lives < 1) {
                        srv->init_command("say Come now, that doesn't make any sense.");
                        return True;
                }
                if(who->query_trait(Trait_Perdition)) {
                        srv->init_command("say I am sorry, but there is nothing that can be done for you.");
                        return True;
                }
                if(lives + who->query_life() > Max_Lives) {
                        srv->init_command("say You can only have a maximum of " + numerical(Max_Lives) + " lives.");
                        return True;
                }
                int cost = Life_Cost * lives;
                if(who->query_wealth() < cost) {
                        srv->init_command("say That would cost " + numerical(cost) + " gold, which is more than you have.");
                        return True;
                }
                srv->init_command("say I will accept a donation of " + numerical(cost) + " gold.");
                who->message(({ 0, ({ "give", 0 }), srv, "the donation" }));
                who->add_wealth(-cost);
                for(int ix = 0; ix < lives; ix++)
                        who->add_life();
                return True;
        }
        if(who->query_ghost()) {
                srv->message(({ 0, ({ "make", 0 }), "the gesture of a cross in the air" }));
                who->revive();
                return True;
        }
        who->message(({ 0, ({ "fall", 0 }), "down on", ({ 'r', 0, "knees" }), "and", ({ "pray", 0 })}));
        srv->message(({ 0, ({ "smile", 0 }), "and", ({ "say", 0 }), "a word of blessing" }));
        return True;
}


void configure() {
    ::configure();
        add_description(({ "a beautiful church altar" }));
        alter_identity(([
            Identity_Nouns              : ({ "altar" }),
            Identity_Adjectives         : ({ "large" }),
        ]));
        set_shape(([
            Shape_Type              : Geometry_Block,
            Shape_Length            : 26.0,
            Shape_Width             : 6.0,
            Shape_Height            : 8.0,
        ]));
        add_proportion(([
            Element_Type                : Material_Marble,
            Element_Proportion          : 1.0,
            Element_Color               : "black",
        ]));
}
