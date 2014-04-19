#include <item.h>
#include <energy.h>
#include <Sinbyen.h>


inherit "/std/item";

internal descriptor skill_mod;

void cloak_do_equip(mapping args) {
        object who = args["who"];
        int amount = min(round(who->query_energy_amount(Energy_Agonistic) * 3000), 40);
        skill_mod = who->add_skill_modifier(([
                Modifier_Index          : ({
                        Skill_Massive_Blow,
                }),
                Modifier_Amount         : amount,
                Modifier_Add_Display    : ([
                        Message_Content     : ({
                                0, ({ "feel", 0 }), "that", ({ 'r', 0, "anger" }), "can now assist you in combat",
                        }),
                        Message_Senses      : Message_Sense_Spiritual,
                ]),
                Modifier_Remove_Display : ([
                        Message_Content     : ({
                                0, ({ "feel", 0 }), "that", ({ 'r', 0, "anger" }), "can no longer assist you in combat",
                        }),
                        Message_Senses      : Message_Sense_Spiritual,
                ]),
        ]));
}

void cloak_do_unequip(mapping args) {
        object who = args["who"];
        who->remove_skill_modifier(&skill_mod);
}




void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns            : ({ "{{white-and-dark red-and-white}crimson cloak}", "crimson cloak", "cloak" }),
    ]));
    add_description(Description_Type_Generic);
    add_description(([
            Description_Type    : Description_Type_Subject_Description,
            Description_Index   : Sinbyen_Definition("subject_crimson_craftmark_guard"),
            Description_Order   : Description_Order_Very_Slightly_Early,
    ]));
    add_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a symbol of leadership amongst the crimson guard",
    }));
    set_craft(Craft_Exquisite);
    armour()->set_autonomon_adapt(True);
    armour()->set_armour_type(Armour_Type_Cloak);
    armour()->set_race("orc");
    add_hook(Do_Equip_Item, #'cloak_do_equip);
    add_hook(Do_Unequip_Item, #'cloak_do_unequip);
    add_proportion(([
        Element_Type               : Material_Cotton,
        Element_Proportion         : 1.0,
        Element_Color            : "red",
    ]));
}
