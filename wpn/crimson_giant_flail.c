#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Weapon("Crimson_Weapon");

void configure() {
        ::configure();
        add_description(([
            Description_Type    : Description_Type_Generic,
            Description_Order   : Description_Order_Very_Early,
        ]));
        add_description(([
            Description_Type    : Description_Type_Simple,
            Description_Content : ({
                "each of", ({ 'r', 0, "three balls" }), "are lined with small barbs and larger spikes",
            }),
            Description_Order   : Description_Order_Slightly_Early,
        ]));
        weapon()->set_autonomon_adapt(True);
        weapon()->set_damage_types(weapon()->query_damage_types() + ({ "shadow" }));
        weapon()->set_weapon_type(Weapon_Type_Giant_Flail);
        set_global_rarity(Rarity_Rare);
        weapon()->set_weapon_skills(([
                Skill_Massive_Blow: 1.25,
        ]));
}