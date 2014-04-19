#include <Sinbyen.h>
#include <item.h>
#include <special_attack.h>

inherit "std/item";
int control;

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
        return "{{airy}a blast of airy energy}";
    }
    if(determine_effect() == "lightning"){
        return "{{lightning}an arc of lightning}";
    }
    if(determine_effect() == "water"){
        return "{{watery}a powerful jet of water}";
    }
    if(determine_effect() == "earth"){
        return "{{earthy}a blast of earthy energy}";
    }
    if(determine_effect() == "mist"){
        return "{{snowy}a cyclone of misty energy}";
    }
    if(determine_effect() == "mud"){
        return "{{filthy}a wave of muddy energy}";
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
        Special_Attack_Message      : ({this_object(),({"kick",this_object()}),"backwards and",blast_descriptor(),"flies at","%e"}),
        Special_Attack_Type         : ({ determine_effect() }),
        Special_Attack_From         : this_object(),
        Special_Attack_Skill        : ({Skill_Telesmatic_Weapon}),
        Special_Attack_Power        : Special_Attack_Power_Strong,
        Special_Attack_Flags        : Special_Attack_Flag_Always_Display,
    ]));
	Special_Attack_Execute(spec, who, target);
	Special_Attack_Flag_On(spec, Special_Attack_Flag_Definite_Article);
}

void nature_call(){
    if(random(2)){
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
                    Craft_Excellent : 50,
                    Craft_Exquisite : 10,
                    Craft_Unearthly : 1,
        ])));
        add_proportion(([
            Element_Type            : hilt_material(),
            Element_Proportion      : 0.50,
            Element_Part            : Part_Binding,
        ]));
        add_proportion(([
            Element_Type            : blade_material(),
            Element_Proportion      : 3.0,
            Element_Flags           : Element_Flag_Provide_Default_Color,
        ]));
        add_proportion(([
            Element_Type            : Material_Dweomer,
            Element_Proportion      : 0.50,
            Element_Flags           : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
            Element_Part            : Part_Aura,
        ]));
        add_hook(Mod_Inflict_Damage, #'nature_call);
}
