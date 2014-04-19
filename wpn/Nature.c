#include <Sinbyen.h>
#include <item.h>
#include <special_attack.h>

inherit "std/item";
int control;
int gaia_pleased = 0;
float bonus;

int determine_worthiness() {
    int worthiness = (user->query_skill(Skill_Animal_Lore) +
    user->query_skill(Skill_Biology) +
    user->query_skill(Skill_Farming) +
    user->query_skill(Skill_Insect_Lore) +
    user->query_skill(Skill_Plant_Lore) +
    user->query_skill(Skill_Sky_Fieldcraft) +
    user->query_skill(Skill_Arctic_Fieldcraft) +
    user->query_skill(Skill_Awareness) +
    user->query_skill(Skill_Desert_Fieldcraft) +
    user->query_skill(Skill_Animal_Lore) +
    user->query_skill(Skill_Forestry) +
    user->query_skill(Skill_Hills_Fieldcraft) +
    user->query_skill(Skill_Jungle_Fieldcraft) +
    user->query_skill(Skill_Mountaineering) +
    user->query_skill(Skill_Plains_Fieldcraft) +
    user->query_skill(Skill_Shorelands_Fieldcraft) +
    user->query_skill(Skill_Spelunking) +
    user->query_skill(Skill_Swamp_Fieldcraft) +
    user->query_skill(Skill_Order_Affinity) +
    user->query_skill(Skill_Underwater_Fieldcraft) -
    user->query_skill(Skill_Torture) -
    user->query_skill(Skill_Demolition) -
    user->query_skill(Skill_Artillery) -
    user->query_skill(Skill_Armour_Operation) -
    user->query_skill(Skill_Machine_Operation) -
    user->query_skill(Skill_Siege_Engineering) -
    user->query_skill(Skill_Chaos_Affinity)     
    / 5);
    return worthiness;
}

void nature_do_equip() {
    if(determine_worthiness() < 500){
        gaia_pleased = 0;
        user->display(([
            Message_Content         : ({
                "A voice in your mind echoes \"Gaia does not know you.  Depart from me\"",
            }),
        ]));
        user->display(([
            Message_Content         : ({
                this_object(),({"grow",this_object()}),"cold to the touch, as though it were rejecting you",
            }),
        ]));
    }
    if(determine_worthiness() > 500 && determine_worthiness() < 1000) {
        gaia_pleased = 1;
        user->display(([
            Message_Content         : ({
                "A voice in you mind echoes \"Gaia counts you a friend, use me as you will\"",
            }),
        ]));
        user->display(([
            Message_Content         : ({
                this_object(),({"grow",this_object()}),"slightly warmer in",({'r',0,"grasp"}),"accepting",({'r',0,"control"}),
            }),
        ]));
    }
    if(determine_worthiness() > 1000){
        gaia_pleased = 2;
        user->display(([
            Message_Content         : ({
                "A voice in your mind echoes \"Gaia knows you well, and has called you ally.  Your enemies shall be hers as well, use me as you will\"",
            }),
        ]));
        user->display(([
            Message_Content         : ({
                this_object(),({"pulse",this_object()}),"with warmth, welcoming",({'r',0,"grasp"}),"eagerly",
            }),
        ]));
    }
}

int hilt_material() {
    return random_element(({
        Material_Cherrywood,
        Material_Ebony,
        Material_Hickory,
        Material_Iron_Oak,
        Material_Ironwood,
        Material_Mahogany,
        Material_Oak,
        Material_Redwood,
        Material_Sandalwood,
        Material_Sycamore,
        Material_Teak,
    }));
}

int blade_material() {
    control = random_element(([
        Material_Copper         : 10,
        Material_Silver         : 25,
        Material_Zinc           : 30,
        Material_Bronze         : 40,
        Material_Iron           : 50,
        Material_Meteoric_Iron  : 25,
        Material_Steel          : 100,
        Material_Adamantite     : 50,
        Material_Adamantium     : 25,
        Material_Carbonite      : 15,
        Material_Mithril        : 10,
        Material_Uru            : 1,
    ]));
    return control;
}

string determine_effect() {
    if(control == Material_Iron || control == Material_Meteoric_Iron || control == Material_Steel){
        return "air";
    }
    if(control == Material_Copper || control == Material_Silver || control == Material_Zinc || control == Material_Bronze){
        return "lightning";
    }
    if(control == Material_Adamantite || control == Material_Adamantium){
        return "water";
    }
    if(control == Material_Carbonite){
        return "earth";
    }
    if(control == Material_Mithril){
        return "mist";
    }
    if(control == Material_Uru){
        return "mud";
    }
}

string blast_descriptor() {
    if(determine_effect() == "air"){
        return "{{airy}blast of airy energy}";
    }
    if(determine_effect() == "lightning"){
        return "{{lightning}arc of lightning}";
    }
    if(determine_effect() == "water"){
        return "{{watery}powerful jet of water}";
    }
    if(determine_effect() == "earth"){
        return "{{earthy}blast of earthy energy}";
    }
    if(determine_effect() == "mist"){
        return "{{snowy}cyclone of misty energy}";
    }
    if(determine_effect() == "mud"){
        return "{{filthy}wave of muddy energy}";
    }
}

int determine_vector(){
    if(determine_effect() == "air"){
        return Vector_Blast;
    }
    if(determine_effect() == "lightning"){
        return Vector_Arc;
    }
    if(determine_effect() == "water"){
        return Vector_Jet;
    }
    if(determine_effect() == "earth"){
        return Vector_Blast;
    }
    if(determine_effect() == "mist"){
        return Vector_Cyclone;
    }
    if(determine_effect() == "mud"){
        return Vector_Wave;
    }
}

void nature_blast() {
    object target = user->query_attacker();
    object room = environment(user);
	object who = user;
	unless(who)
		return;
	unless(target)
		return;
    descriptor spec = Special_Attack(([
        Special_Attack_Vector       : determine_vector(),
        Special_Attack_Message      : ({this_object(),({"rumble",this_object()}),"as a {{shimmering}pulse of energy} runs the length of",this_object(),"and produces",'a',blast_descriptor(),"that shoots toward","%e"}),
        Special_Attack_Type         : ({ determine_effect() }),
        Special_Attack_From         : this_object(),
        Special_Attack_Skill        : ({Skill_Telesmatic_Weapon}),
        Special_Attack_Power        : Special_Attack_Power_Strong,
        Special_Attack_Strike       : Special_Attack_Strike_Accurate,
        Special_Attack_Flags        : Special_Attack_Flag_Always_Display,
    ]));
	Special_Attack_Execute(spec, who, target);
	Special_Attack_Flag_On(spec, Special_Attack_Flag_Definite_Article);
}

void nature_call(){
    if(gaia_pleased == 0){
        return;
    }
    if(!random(8)){
        call_out("nature_blast", 2);
    }
}

void configure() {
        ::configure();
        set_global_rarity(Rarity_Rare);
        set_craft(random_element(([
                    Craft_Poor      : 1,
                    Craft_Fair      : 50,
                    Craft_Good      : 100,
                    Craft_Excellent : 75,
                    Craft_Exquisite : 25,
                    Craft_Unearthly : 1,
        ])));
        add_proportion(([
            Element_Type            : hilt_material(),
            Element_Proportion      : 0.75,
            Element_Part            : Part_Binding,
        ]));
        add_proportion(([
            Element_Type            : blade_material(),
            Element_Proportion      : 3.0,
            Element_Flags           : Element_Flag_Provide_Default_Color,
        ]));
        add_proportion(([
            Element_Type            : Material_Dweomer,
            Element_Proportion      : 0.01,
            Element_Flags           : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
            Element_Part            : Part_Aura,
        ]));
        add_hook(Mod_Inflict_Damage, #'nature_call);
        add_hook(Do_Equip_Item, #'nature_do_equip);
        add_description(([
            Description_Type        : Description_Type_Generic,
            Description_Order       : Description_Order_Very_Early,
        ]));
        weapon()->set_weapon_type(random_element(([
            Weapon_Type_Longsword   : 8,
            Weapon_Type_Greatsword  : 8,
            Weapon_Type_Greataxe    : 5,
            Weapon_Type_Greatspear  : 5,
            Weapon_Type_Morning_Star: 5,
            Weapon_Type_Claw        : 5,
            Weapon_Type_Shortsword  : 5,
            Weapon_Type_Spear       : 5,
            Weapon_Type_Warhammer   : 5,
            Weapon_Type_Halberd     : 4,
            Weapon_Type_Scythe      : 2,
            Weapon_Type_Dagger      : 4,
            Weapon_Type_Staff       : 2,
            Weapon_Type_Whip        : 2,
            Weapon_Type_Trident     : 1,
            Weapon_Type_No_Dachi    : 1,
            Weapon_Type_Wingblade   : 1,
            Weapon_Type_Katana      : 1,
            Weapon_Type_Giant_Axe   : 1,
            Weapon_Type_Giant_Sword : 1,
            Weapon_Type_Giant_Scythe: 1,
            Weapon_Type_Giant_Hammer: 1,
            Weapon_Type_Giant_Spear : 1,
            Weapon_Type_Giant_Whip  : 1,
        ])));            
        weapon()->set_autonomon_adapt(True);
        weapon()->set_damage_types(weapon()->query_damage_types() + ({ determine_effect() }));
        set_global_rarity(Rarity_Rare);
        weapon()->set_weapon_skills(([
                Skill_Discipline        : 0.5,
                Skill_Precision_Strike  : 0.5,
        ]));
        string weapon_type = this_object()->weapon()->type()->query_weapon_type_identity();
        mixed elements = this_object()->query_visible_elements();
        add_known_description(({
            'v',({"recognize",'v'}),({'v',0}),"as an enchanted weapon of nature's wrath",
        }));
        add_known_description(({
            "Bound by forces only Sint Skogen of Sinbyen is privy to, this weapon is capable of unleashing the forces of nature itself to those that would oppose it",
        }));
        alter_identity(([
            Identity_Effect     : "nature's wrath",
        ]));
        set_identify_skills(([
            Skill_Legend_Lore       : 90,
            Skill_Plant_Lore        : 60,
        ]));
}