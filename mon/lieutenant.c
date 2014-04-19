#include <Sinbyen.h>
#include <autonomon.h>
#include <speech.h>

inherit Sinbyen_Monster("Crimson_Guard");

void guard_create() {
    set_weapon_class(12, Limb_Type_Hand, ({"crushing", "force" }));
    init_command("stop attacking with kick");
    init_command("stop attacking with eye gouge");
    init_command("wear all");
}

void configure() {
    ::configure();
    set_title("the Crimson lieutenant");
    alter_identity(Identity_Special_Names, ({ "SINBYEN_LEADER" }), Identity_Alter_Add);
    set_chat(5, ({
        ";scan the area",
        "nod at %p",
        "say Good day. to %p",
        ";glance around",
        "say Honor the law.",
        "say Greetings.",
    }));
    add_skill_points(Skill_Precision_Strike, 200);
    add_skill_points(Skill_Hardiness, 400);
    add_skill_points(Skill_Leadership, 300);
    add_skill_points(Skill_Dodge, 300);
    add_skill_points(Skill_Quickness, 300);
    add_skill_points(Skill_Axe, 300);
    add_skill_points(Skill_Sword, 300);
    add_special_attack(([
        Special_Attack_Name         : ({ "Queen's Thrust" }),
        Special_Attack_Vector       : Vector_Blade,
        Special_Attack_Message      : ({ 0, ({ "thrust", 0 }), "%c", "forward with both hands, with amazing speed", }),
        Special_Attack_Type         : ({ "cutting", "piercing" }),
        Special_Attack_Skill        : ({ Skill_Sword, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greatsword),
        Special_Attack_Activity     : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Large,
    ]));
    add_special_attack(([
        Special_Attack_Name         : ({ "Clean Split" }),
        Special_Attack_Vector       : Vector_Strike,
        Special_Attack_Message      : ({ 0, ({ "swing", 0 }), "%c", "downward at an angle", "%e", "with all", ({ 'r', 0, "might" }), }),
        Special_Attack_Type         : ({ "cutting", "piercing", "crushing", }),
        Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
        Special_Attack_Power        : Special_Attack_Power_Very_Extreme,
        Special_Attack_Condition    : Weapon_Required(Weapon_Type_Greataxe),
        Special_Attack_Activity     : 20,
        Special_Attack_Chance       : Special_Attack_Chance_Infrequent,
        Special_Attack_Size         : Special_Attack_Size_Very_Large,
    ]));
}

void create() {
        ::create();
        unless(query_name_descriptor() || !query_race())
                generate_name_descriptor();
                call_out("guard_create", 2);
}
