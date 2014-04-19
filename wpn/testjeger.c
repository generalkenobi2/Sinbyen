#include <item.h>
#include <special_attack.h>
#include <Sinbyen.h>
#include <energy.h>

inherit "/std/item";

float charge = 0.00;
float max_charge = 500.00;
float amount = 0.00;

float query_charge(mapping args) {
    return charge;
}

int axe_hit(mapping args) {
	object user = query_user();
	object target = args["target"];
	if(!user || !target || args["deflecting"] || args["ranged"])
		return 0;	
    int dam = random(9);
	object room = environment(user);
	switch(dam) {
	case 0  :
		break;
    case 1  :
        if(user->query_energy_amount(Energy_Agonistic) < 20) {
            user->message(({({ 's', 0, this_object() }), ({ "flash", this_object() }), "brightly and momentarily", ({ "appear", this_object() }), "red hot"}));
            user->display(({({ 's', 0, this_object() }), ({ "send", this_object() }), "pain rushing through", ({ 'r', 0, "body"}), "filling you with anger"}));
            user->do_damage((15), environment(), -1, ({ "heat" }), this_object());
            user->add_energy_amount(Energy_Agonistic, 100);
            
            break;
        }
        else{
            amount = user->query_energy_amount(Energy_Agonistic) * 0.4;
            user->message(({({ 's', 0, this_object() }), ({ "growl", this_object() }), "greedily and {{shimmering dark red}dark red tendrils of energy} flow from", ({ 'r', 0, "body" }), "into", ({ 's', 0, this_object() })}));
            charge = charge + amount;
            user->display("{{dark gray}You feel your rage slipping away.}");
            user->remove_energy_amount(Energy_Agonistic, amount);
            if(charge > 250.00) {
                user->message(({({ 's', 0, this_object() }),'j',"{{shimmering dark red}",({ "radiate", this_object() }),"brilliantly}"}));
            }
            if(charge > max_charge) {
                charge = 250.00;
                user->message(({({ 's', 0, this_object()}),'j',"{{fiery yellow}",({ "explode", this_object()}),"}, creating a massive {{fiery}pillar of fire} and {{shimmering dark red}swirling hatred} around", target}));
                target->do_damage(800 + random(400), environment(), -1, ({ "heat", "psionic", "fire"}), this_object());
                target->stun_living(6 + random(9), 0, ({ "psionic", "fire", "heat" }));
            }
        }
		break;
	case 2  :
		user->message(({({ 's', 0, this_object() }), ({ "growl", this_object() }), "and {{shimmering dark red}dark red tendrils} glow around", ({ 's', 0, this_object() })}));
        charge = charge + 40.00;        
        if(charge > 250.00) {
            user->message(({({ 's', 0, this_object() }),'j',"{{shimmering dark red}",({ "radiate", this_object() }),"brilliantly}"}));
        }
        if(charge > max_charge) {
                charge = 250.00;
                user->message(({({ 's', 0, this_object()}),'j',"{{fiery yellow}",({ "explode", this_object()}),"}, creating a massive {{fiery}pillar of fire} and {{shimmering dark red}swirling hatred} around", target}));
                target->do_damage(800 + random(400), environment(), -1, ({ "heat", "psionic", "fire"}), this_object());
                target->stun_living(6 + random(9), 0, ({ "psionic", "fire", "heat" }));
        }
		break;
	case 3 .. 4  :
        amount = target->query_energy_amount(Energy_Agonistic) / 2.00;
        user->message(({ "{{shimmering dark red}glowing tendrils of dark red energy} flow out of", target, "and into", ({ 's', 0, this_object() })}));
        target->remove_energy_amount(Energy_Agonistic, amount);
        target->stun_living(1, 0, ({ "psionic" }));
        charge = charge + amount;
        
        if(charge > 250.00) {
            user->message(({({ 's', 0, this_object() }),'j',"{{shimmering dark red}",({ "radiate", this_object() }),"brilliantly}"}));
        }
        if(charge > max_charge) {
                charge = 250.00;
                user->message(({({ 's', 0, this_object()}),'j',"{{fiery yellow}",({ "explode", this_object()}),"}, creating a massive {{fiery}pillar of fire} and {{shimmering dark red}swirling hatred} around", target}));
                target->do_damage(800 + random(400), environment(), -1, ({ "heat", "psionic", "fire"}), this_object());
                target->stun_living(6 + random(9), 0, ({ "psionic", "fire", "heat" }));
        }
        break;
	case 5  :
        if (charge < 20.00) { user->message(({({ 's', 0, this_object() }), ({ "growl", this_object() }), "softly"}));
        
            break;
        }
        else {
            charge = charge - 20.00;
            user->message(({({ 's', 0, this_object() }), ({ "roar", this_object() }), "thunderously"}));
            target->message(({ 0, ({ "are", 0 }), "struck by a shockwave of searing thunder" }));
            target->stun_living(3 + random(6), 0, ({ "sonic", "fire", "heat" }));
            target->do_damage(100 + random(100), environment(), -1, ({ "sonic", "fire", "heat" }), this_object());
        }
		break;
	case 6  :
        if(charge < 20) { user->message(({({ 's', 0, this_object() }),'j',"{{shimmering dark red}", ({ "flicker", this_object() }), "dimly}"}));
            break;
        }
        else {
            charge = charge - 20.00;
            user->message(({({ 's', 0, this_object() }), ({ "surround", this_object() }), user, "with a {{shimmering dark red}shimmering red aura}"})) + user->display("{{pink}You feel rejuvenated.}");
            user->add_endurance(20 + random(50));
            user->heal_living(30 + random(50));
            
        }
		break;
	case 7 .. 8  :
        user->message(({({ 's', 0, this_object()}),'j',"{{fiery}",({ "flare", this_object()}),"violently}"}));
		user->message(({ "Several {{fiery}shards of searing metal} erupt from", ({ 's', 0, this_object() }), "and embed themselves in", target }));
		target->do_damage(50 + random(100), environment(), -1, ({ "heat", "metal" }), this_object());
        target->add_energy_amount(Energy_Agonistic, 250);
        target->display("{{pink}A wave of anger rushes through you.}");
        
		break;
	case 9  :
		 if( charge < 100.00) { user->message(({({ 's', 0, this_object() }), ({ "start", this_object() }), "rumbling but quickly", ({ "grow", this_object() }), "silent"}));
            break;
        }
        else {
            charge = charge - 60.00;
            user->message(({({ 's', 0, this_object() }), ({ "start", this_object() }), "rumbling furiously and a shockwave searing thunder erupts from", ({ 's', 0, this_object() }), "striking", target}));
            target->do_damage(150 + random(300), environment(), -1, ({ "heat", "metal" }), this_object());
            user->stun_living(3 + random(9), 0, ({ "sonic", "fire", "heat" }));
        }
		break;
	}
	return dam;
}

void configure() {
    ::configure();
    add_hook(Mod_Inflict_Damage, #'axe_hit);
    set_properties(({
        Prop_Aflame,
    }));
    alter_identity(([
        Identity_Name           : "Testjeger",
        Identity_Adjectives     : ({({ "scratch-marked", "blood-spattered" })}),
        Identity_Flags          : Identity_Flag_Proper,
    ]));
    set_identify_skills(([
        Skill_Legend_Lore       : 90,
    ]));
    
    add_description(({
        "This is", 'a',
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Content : Description(Description_Type_Weapon_Type_Name),
            Description_Flags   : Description_Flag_Adjective,
        ])),
        "of",
        Description(Description_Type_Craftsmanship_Name),
        "craftsmanship",
    }));
    add_description(({
        ({ 'p', 0 }), ({ "emit", 0 }), "a {{white}soft glow} and occasionally", ({"let", 0 }), "off small showers of {{fire}sparks}",
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }),  ({ 'v', 0 }), "as Hestjeger, the axe of Thurgg Bloodfist of The Crimson Fist",
    }));
    add_known_description(({
        "legends say",({ 'p', 0 }), ({ "were", 0 }), "forged with phoenix fire",
    }));
    add_description(({
       ({ 'p', 0 }), ({ "are", 0 }), "worn down with use but", ({ "retain", 0 }), ({ 'r', 0, "good condition"}),
    }));
    add_description(({
        ({ 'r', 0, "blade" }), "is held in place by an ornamental gnoll",
    }));
    add_description(({
        "the gnoll grips the blade firmly within his claws, and is furiously snarling over it's top edge",
    }));
    add_description(({
        "the entire shaft appears to be made of",
        
            Description(([
                        Description_Type                    : Description_Type_Element_Name,
                        Description_Index                   : Element(([
                        Element_Type                        : Material_Uru,
                        Element_Color                       : "blood-red",
                        ])),
                    ])),
        
    }));
    
    set_unique(True);
    set_craft(Craft_Unearthly);
    weapon()->add_weapon_feature_modifier(([
                Modifier_Index      : Weapon_Feature_Damage,
                Modifier_Amount     : 5.0,
                Modifier_Bound      : 5.0,
                Modifier_Flags      : Modifier_Flag_Persistent,
    ]));
    weapon()->add_weapon_feature_modifier(([
                Modifier_Index      : Weapon_Feature_Penetrate,
                Modifier_Amount     : 5.0,
                Modifier_Bound      : 5.0,
                Modifier_Flags      : Modifier_Flag_Persistent,
    ]));
    weapon()->set_weapon_type(Weapon_Type_Greataxe);
    weapon()->set_damage_types(({ "heat", "cutting", "fire" }));
    set_known_value_added(5000);
    add_proportion(([
        Element_Type             : Material_Uru,
        Element_Proportion       : 1.50,
        Element_Color            : "blood-red",
    ]));
    add_proportion(([
        Element_Type             : Material_Steel,
        Element_Proportion       : 0.50,
        Element_Color            : "black",
    ]));
    add_proportion(([
        Element_Type             : Material_Logos,
        Element_Proportion       : 0.10,
    ]));
}
