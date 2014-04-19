#include <command.h>
#include <item.h>

inherit "/std/item";

private string orig_strike;

void ren_synchronize(object who) {
        if(who->combat_mode()->query_combat_mode_suppress_strike_location())
                return;
        object att = who->query_attacker();
        if(att) {
                int loc = who->query_strike_location_resolved(att);
                if(loc != Null && Limb_Base_Type(att->query_limb_type(loc)) == Limb_Type_Head)
                        return;
                int array locs = att->existing_limbs(Limb_Type_Head);
                if(!sizeof(locs))
                        return;
                who->init_command("set strike location to " + att->query_limb_name(random_element(locs)), Command_Flags_System | Command_Flag_Fail_Silently);
        } else {
                if(who->query_strike_location() != "head")
                        who->init_command("set strike location to head", Command_Flags_System | Command_Flag_Fail_Silently);
        }
}

void ren_do_equip(mapping args) {
        object who = args["who"];
        orig_strike = who->query_strike_location();
        ren_synchronize(who);
}

void ren_do_unequip(mapping args) {
        object who = args["who"];
        if(orig_strike && orig_strike != who->query_strike_location())
                who->init_command("set strike location to " + orig_strike, Command_Flags_System | Command_Flag_Fail_Silently);
}

int ren_cause_damage(descriptor dxr) {
        object user = Attack_Query(dxr, Attack_Aggressor);
        object targ = Attack_Query(dxr, Attack_Target);
        unless(user && targ && !Attack_Flag_Check(dxr, Attack_Flag_Hypothetical))
                return 0;
        ren_synchronize(user);
        mixed limb = Attack_Query(dxr, Attack_Limb);
        int head_size = 0;
        int total_size = 0;
        foreach(int ix : targ->query_specified_limbs_indices(limb)) {
                int size = targ->query_limb_size(ix);
                if(Limb_Base_Type(targ->query_limb_type(ix)) == Limb_Type_Head)
                        head_size += size;
                total_size += size;
        }
        float how_much_head = to_float(head_size) / to_float(total_size);
        if(how_much_head > 0 && random(120) < how_much_head * 100)
                user_message(([
                        Message_Content : ({
                                0, ({ "ring", 0 }), "on impact.",
                        }),
                ]));
        return round((Attack_Query(dxr, Attack_Damage_Rating) + Attack_Query(dxr, Attack_Rating)) * (-1.4 + how_much_head * 2));
}

void configure() {
        ::configure();
        set_creator(({ "kenobi" }));
        set_unique(True);
        set_identify_skills(([
        Skill_Sephirotic_Lore       : 50,
        Skill_Weapon_Lore           : 120,
        ]));
        alter_identity(([
                Identity_Name           : "Ren",
                Identity_Adjectives     : ({({ "beautiful" })}),
                Identity_Flags          : Identity_Flag_Proper,
        ]));
        add_description(Description_Type_Generic);
        add_known_description(({
            'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as Ren, the holy sword said to have been made by Yehovah himself to cleanse the the world of its impurity",
        }));
        set_craft(Craft_Unearthly);
        weapon()->set_weapon_type(Weapon_Type_Longsword);
        weapon()->set_weapon_attack_size(1);
        weapon()->set_damage_types(({ "holy", "spirit", "order", }) + weapon()->query_damage_types());
        weapon()->set_weapon_skills(([
                Skill_Precision_Strike      : 1.0,
                Skill_Sephirotic_Affinity   : 2.0,
                Skill_Order_Affinity        : 0.75,
                
    ]));
        weapon()->add_weapon_feature_modifier(([
                Modifier_Index            : Weapon_Feature_Strike,
                Modifier_Amount           : 12.0,
                Modifier_Flags            : Modifier_Flag_Persistent,
        ]));
        weapon()->add_weapon_feature_modifier(([
                Modifier_Index            : Weapon_Feature_Agonize,
                Modifier_Amount           : -20.0,
                Modifier_Flags            : Modifier_Flag_Persistent,
        ]));
        set_known_value_added(5000);
        add_hook(Do_Equip_Item, #'ren_do_equip);
        add_hook(Do_Unequip_Item, #'ren_do_unequip);
        add_hook(Mod_Cause_Damage, #'ren_cause_damage);
        set_properties(({
            Prop_Holy,
        }));
        add_proportion(([
                Element_Type                : Material_Uru,
                Element_Proportion          : 3.0,
                Element_Part                : Part_Core,
                Element_Flags               : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
        ]));
        add_proportion(([
                Element_Type                : Material_Adamantium,
                Element_Proportion          : 0.5,
                Element_Part                : Part_Coat,
        ]));
        add_proportion(([
                Element_Type                : Material_Kedusham,
                Element_Proportion          : 0.1,
                Element_Part                : Part_Aura,
                Element_Flags               : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
        ]));
        add_proportion(([
                Element_Type                : Material_Lexoth,
                Element_Proportion          : 0.5,
                Element_Part                : Part_Infusion,
                Element_Flags               : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
        ]));
        add_proportion(([
                Element_Type                : Material_Gold,
                Element_Proportion          : 0.5,
                Element_Part                : Part_Inlay,
        ]));
}
