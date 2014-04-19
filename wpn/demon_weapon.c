#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Weapon("Weapon");

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        add_description(({
            "billowing {{shadowfire}clouds of shadow} continuously roll off of", ({ 'o', 0 }),
        }));
        weapon()->set_autonomon_adapt(True);
        weapon()->set_damage_types(({ "shadow", "spirit" }) + weapon()->query_damage_types());
        weapon()->set_weapon_type(random_element(({
                                Weapon_Type_Giant_Spear,
                                Weapon_Type_Giant_Axe,
                                Weapon_Type_Giant_Flail,
                                Weapon_Type_Giant_Sword,
                                Weapon_Type_Giant_Hammer,
                                Weapon_Type_Giant_Scythe,                                
                                }))
        );
        set_global_rarity(Rarity_Rare);
        weapon()->set_weapon_skills(([
                Skill_Qlippotic_Affinity: 1.25,
        ]));
}
