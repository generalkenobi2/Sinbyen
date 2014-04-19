#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Weapon("Weapon");

void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        weapon()->set_autonomon_adapt(True);
        weapon()->set_weapon_type(random_element(({
                                Weapon_Type_Greatspear,
                                Weapon_Type_Greataxe,
                                Weapon_Type_Great_Flail,
                                Weapon_Type_Greatsword,
                                Weapon_Type_Great_Hammer,
                                }))
        );
        set_global_rarity(Rarity_Rare);
        weapon()->set_weapon_skills(([
                Skill_Qlippotic_Affinity: 1.25,                
    ]));
}
