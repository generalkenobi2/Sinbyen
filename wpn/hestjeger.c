#include <item.h>
#include <special_attack.h>
#include <Sinbyen.h>
#include <energy.h>
#include <versus.h>

inherit "/std/item";

float charge = 0.00;
float max_charge = 500.00;
float amount = 0.00;
private descriptor attr_mod;
private descriptor skill_mod;
int time;

float hestjeger_query_charge() {
    return charge;
}

void hestjeger_set_charge(float amt) {
    charge = amt;
}

void hestjeger_add_charge(float val) {
	float amt = hestjeger_query_charge();
	amt += val;
	amt = max(amt, 0.0);
	hestjeger_set_charge(amt);
}

void hestjeger_horse_hate() {
    int loop = 0;
    object array nearby = user->query_nearby_character_objects();
    int size = sizeof(nearby);
    //user->display(({"{{green}hestjeger_horse_hate() called!}",
        //"{{green}Detecting",numerical(size),"object(s) nearby!}",}));
    if(size == 0) {
        return;
    }
    while(loop < (size)) {
        if(nearby[loop]->race()->query_race_category("equine") && nearby[loop]->is_incarnos() == 0 && nearby[loop]->query_incarnos_control() == 0 && nearby[loop]->query_owner()->is_incarnos() == 0) {
            if(time() > time){
                time = time() + 5;
                user->display(([
                    Message_Content     : ({
                        0, ({"are",0}),"overcome with an uncontrolable hatred of",nearby[loop],
                    }),
                    Message_Color       : "opalescent red",
                ]));
            }
            user->add_attacker(nearby[loop]);
        }
        if(nearby[loop]->race()->query_race_category("equine")){
            if(time() > time){
                time = time() + 5;
                environment()->message(([
                    Message_Content                             : ({
                        ({ 's', 0, this_object() }), ({"sizzle",this_object()}),"with rage.",
                    }),
                    Message_Color                               : "shimmering red",
                ]));
            }
        }
        //user->display(({"{{green}object number",numerical(loop),"is",nearby[loop],".}"}));
        //user->display(({"{{green}time span is",numerical(time-time()),".}"}));
        loop++;
    }
}


void hate_call() {
    call_out("hestjeger_horse_hate", 5);
}

void axe_do_equip(mapping args) {
    object user = query_user();
    attr_mod = args["who"]->add_attribute_modifier(([
        Modifier_Index  : Attr_Str,
        Modifier_Amount : 80,
    ]));
    skill_mod = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Axe,
        Modifier_Amount : 80,
    ]));
    user->display(([
        Message_Content         : ({
            ({'r',0,"body"}), "is flooded with terrible, seething anger.",
        }),
        Message_Color           : "shimmering red",
    ]));
    user->display(([
        Message_Content         : ({
            0, ({"feel",0}), "stronger and faster, at one with", this_object(), ".",
        }),
        Message_Color           : "bright pink",
    ]));
    user->add_energy_amount(Energy_Agonistic, 150);
    user->add_hook(Do_Move, #'hate_call);
}

void axe_do_unequip(mapping args) {
    object hestjeger = this_object();
    args["who"]->remove_attribute_modifier(&attr_mod);
    args["who"]->remove_skill_modifier(&skill_mod);
    args["who"]->message(([
        Message_Content         : ({
            ({'s', 0, hestjeger}), ({"grow",hestjeger}), "quiet",
        }),
    ]));
    args["who"]->display(([
        Message_Content         : ({
            0, ({"feel",0}), "weaker and less skilled."
        }),
        Message_Color           : "dark gray",
    ]));
    args["who"]->remove_hook(Do_Move, #'hate_call);
}

descriptor ruby(string color) {
	return  Description(([
                Description_Type   : Description_Type_Element_Name,
                Description_Index  : Element(([
                    Element_Type   : Material_Ruby,
                    Element_Color  : color,
                    Element_Flags  : Element_Flag_Suppress_Color_Name,
                ])),
            ]));
}

void hestjeger_jet() {
    charge = charge - 20.00;
	
	unless(user)
		return;
	object target = user->query_attacker();
	unless(target)
		return;
    target->add_energy_amount(Energy_Agonistic, 180);
    descriptor spec = Special_Attack(([
        Special_Attack_Vector       : Vector_Jet,
        Special_Attack_Message      : ({this_object(),({"fire",this_object()}),"{{orange-streaked white}a jet of searing steam} at", "%e"}),
        Special_Attack_Type         : ({ "fire", "air", "water"}),
        Special_Attack_From         : this_object(),
        Special_Attack_Skill        : ({Skill_Axe, Skill_Pyraturgy, Skill_Telesmatic_Weapon}),
        Special_Attack_Power        : Special_Attack_Power_Very_Strong,
        Special_Attack_Damage_Shifts: ([
            Damage_Mode_Agonize     : 0.75
        ]),
        Special_Attack_Flags        : Special_Attack_Flag_Always_Display,
    ]));
	Special_Attack_Execute(spec, user, target);
}

void hestjeger_shockwave() {
	
    descriptor ruby = ruby("bright red");
	unless(user)
		return;
	object target = user->query_attacker();
	unless(target)
		return;
    descriptor spec = Special_Attack(([
        Special_Attack_Vector       : Vector_Wave,
        Special_Attack_Message      : ({this_object(),({"blast",this_object()}),"a {{bright orange}wave of searing thunder} toward", "%e"}),
        Special_Attack_Type         : ({ "fire", "heat", "sonic", "electrical"}),
        Special_Attack_From         : this_object(),
        Special_Attack_Skill        : ({Skill_Axe, Skill_Pyraturgy, Skill_Telesmatic_Weapon, Skill_Massive_Blow}),
        Special_Attack_Power        : Special_Attack_Power_Very_Powerful,
        Special_Attack_Damage_Shifts: ([
            Damage_Mode_Stun        : 0.75
        ]),
        Special_Attack_Flags        : Special_Attack_Flag_Always_Display,
    ]));
	Special_Attack_Execute(spec, user, target);
}

void hestjeger_overcharge() {
    charge = 100.00;
	
    descriptor ruby = ruby("bright red");
	unless(user)
		return;
	object target = user->query_attacker();
	unless(target)
		return;
    descriptor spec = Special_Attack(([
        Special_Attack_Vector       : Vector_Column,
        Special_Attack_Message      : ({this_object(),({"rumble",this_object()}),"and",({'r',this_object(),ruby}),({"flare",ruby}),"violently, creating a {{fiery-and-fiery yellow-and-fiery}fiery column of swirling hatred} around", "%e"}),
        Special_Attack_Type         : ({ "fire", "heat", "primal"}),
        Special_Attack_From         : this_object(),
        Special_Attack_Skill        : ({Skill_Axe, Skill_Pyraturgy, Skill_Telesmatic_Weapon, Skill_Massive_Blow, Skill_Precision_Strike}),
        Special_Attack_Power        : Special_Attack_Power_Very_Overwhelming,
        Special_Attack_Modifier     : 200,
        Special_Attack_Flags        : Special_Attack_Pass_Flag_Untreatable,
        Special_Attack_Flags        : Special_Attack_Flag_Always_Display,
    ]));
	Special_Attack_Execute(spec, user, target);
}

int axe_hit(mapping args) {
    descriptor ruby = ruby("bright red");
    object target = args["target"];
    object hestjeger = this_object();
    if(!user || !target || args["deflecting"] || args["ranged"])
        return 0;    
    int dam = random(10);
    object room = environment(user);
    if(target->query_race() == "horse" || target->query_race() == "sleipnir" || target->query_race() == "unicorn" || target->query_race() == "pegasus" || target->query_race() == "zebra") {
        environment()->message(([
            Message_Content                             : ({
                ({ 's', 0, this_object() }), ({"sizzle",this_object()}),"with rage.",
            }),
            Message_Color                               : "shimmering red",
        ]));
        hestjeger_overcharge();
        return 0;
    }
    else {
        switch(dam) {
        case 0  :
            if(user->query_energy_amount(Energy_Agonistic) < 20) {
                user->message(([
                    Message_Content                     : ({
                        ({'s',0,hestjeger}),
                            ([
                                Message_Content         : ({ 
                                   ({"flash",hestjeger}), "brightly",
                                }),
                                Message_Color           : "shimmering white",
                            ]),
                        "and momentarily", ({"glow",hestjeger}),
                            ([
                                Message_Content         : ({
                                    "red hot",
                                }),
                                Message_Color           : "bright orange",
                            ]),
                        ".",
                    }),
                ]));
                user->display(([
                    Message_Content                     : ({
                        ({'s',0,hestjeger}),({"send",hestjeger}),"pain rushing through",
                        ({ 'r', 0, "body"}),", filling you with anger.",
                    }),
                    Message_Color                       : "shimmering red",
                ]));            
                user->do_damage(([
                    Attack_Damage                       : semirandom(50),
                    Attack_Damage_Type                  : ({ "heat" }),
                    Attack_Limb                         : query_current_limbs_bound(),
                    Attack_Weapon                       : this_object(),
                    Attack_With                         : ({ "contact with", this_object() }),
                    Attack_Flags                        : Attack_Flag_Display_Damage_Message,
                ]));
                user->add_energy_amount(Energy_Agonistic, 100);
                
                break;
            }
            else{
                amount = user->query_energy_amount(Energy_Agonistic) * 0.4;
                user->message(([
                    Message_Content                     : ({
                        ({'s',0,hestjeger}),({"growl",hestjeger}),"hungrily and",
                            ([
                                Message_Content         : ({
                                    "a throbbing cloud of bright red energy",
                                }),
                                Message_Color           : "shimmering bright red",
                            ]),
                        ({ 'r', 0, "body" }),"into",({'s',0,hestjeger}),
                    }),
                ]));
                charge += amount;
                user->display(([
                    Message_Content                     : ({
                        "You feel your rage being drained away.",
                    }),
                    Message_Color                       : "dark gray",
                ]));
                user->remove_energy_amount(Energy_Agonistic, amount);
                if(charge > 250.00) {
                    user->message(([
                        Message_Content                 : ({
                            ({'s',hestjeger,ruby}),
                                ([
                                    Message_Content     : ({
                                       ({"radiate",ruby}),"brilliantly",
                                    }),
                                    Message_Color       : "shimmering bright red",
                                ]),
                        }),
                    ]));
                }
                if(charge > max_charge) {
                    hestjeger_overcharge();
                }
            }
            break;
        case 1 .. 2  :
            user->message(({({ 's', 0, this_object() }), ({ "growl", this_object() }), "and a {{shimmering bright red}throbbing cloud of bright red energy} glows around", ({ 's', 0, this_object() })}));
            charge = charge + 40.00;        
            if(charge > 250.00) {
                    user->message(([
                        Message_Content                 : ({
                            ({'s',hestjeger,ruby}),
                                ([
                                    Message_Content     : ({
                                       ({"radiate",ruby}),"brilliantly",
                                    }),
                                    Message_Color       : "shimmering bright red",
                                ]),
                        }),
                    ]));
            }
            if(charge > max_charge) {
                hestjeger_overcharge();
            }
            break;
        case 3 .. 4  :
            amount = target->query_energy_amount(Energy_Agonistic) / 2.00;
            user->message(([
                Message_Content                         : ({
                    ([
                        Message_Content                 : ({
                            "A throbbing cloud of bright red energy",
                        }),
                        Message_Color                   : "shimmering bright red",
                    ]),
                    "flows out of",target,"and into",({ 's', 0, this_object() }),
                }),
                Message_Senses                          : Message_Sense_Astral,
            ]));
            target->remove_energy_amount(Energy_Agonistic, amount);
            target->stun_living(1, 0, ({ "psionic" }));
            charge = charge + amount;
            if(charge > 250.00) {
                user->message(([
                    Message_Content                     : ({
                        ({'s',hestjeger,ruby}),
                            ([
                                Message_Content         : ({
                                   ({"radiate",ruby}),"brilliantly",
                                }),
                                Message_Color           : "shimmering bright red",
                            ]),
                    }),
                ]));
            }
            if(charge > max_charge) {
                hestjeger_overcharge();
            }
            break;
        case 5  :
            if (charge < 20.00) {
                user->message(([
                    Message_Content                     : ({
                        ({ 's', 0, this_object() }),({ "growl", this_object() }), "softly",
                    }),
                ]));        
                break;
            }
            else {
                charge = charge - 20.00;
                user->message(([
                    Message_Content                     : ({
                        ({ 's', 0, this_object() }),({ "release", this_object() }), "a thunderous shockwave",
                    }),
                ]));
                hestjeger_shockwave();
            }
            break;
        case 6  :
            if(charge < 20) { user->message(([
                Message_Content                         : ({
                    ({ 's', 0, this_object() }),
                        ([
                            Message_Content             : ({
                                ({ "flicker", this_object() }), "dimly",
                            }),
                        ]),
                }),
                Message_Senses                          : Message_Sense_Visual,
            ]));
            break;
            }
            else {
                charge = charge - 20.00;
                user->message(([
                    Message_Content                     : ({
                        ({ 's', 0, this_object() }),({ "surround", this_object() }),user,"with a",
                            ([
                                Message_Content         : ({
                                    "bright red aura.",
                                }),
                                Message_Color           : "shimmering bright red",
                            ]),
                    }),
                    Message_Senses                      : Message_Sense_Astral,
                ]));
                user->display(([
                    Message_Content                     : ({
                        "You feel rejuvenated.",
                    }),
                    Message_Color                       : "pink",
                ]));
                user->add_endurance(20 + random(50));
                user->heal_living(30 + random(50));
                
            }
            break;
        case 7 .. 8  :
            hestjeger_jet();
            break;
        case 9  :
             if( charge < 100.00) {
                user->message(([
                    Message_Content                     : ({
                        ({ 's', 0, this_object() }), ({ "start", this_object() }),
                        "rumbling but quickly",({ "grow", this_object() }), "silent.",
                    }),
                ]));
                break;
            }
            else {
                charge = charge - 60.00;
                hestjeger_shockwave();
            }
            break;
        }
        return dam;
    }
}

void configure() {
    ::configure();
    set_properties(({
        Prop_Aflame,
    }));
    alter_identity(([
        Identity_Name           : "Hestjeger",
        Identity_Flags          : Identity_Flag_Proper,
    ]));
    set_identify_skills(([
        Skill_Legend_Lore       : 90,
    ]));

    add_description(Description_Type_Generic);
    add_description(({
        ({ 'p', 0 }), ({ "emit", 0 }), "a {{white}warm glow} and occasionally", ({"let", 0 }), "off {{fire}small showers of sparks}",
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }),  ({ 'v', 0 }), "as Hestjeger, the axe of Thurgg Bloodfist of The Crimson Fist",
    }));
    add_known_description(({
        "legends say",({ 'p', 0 }), ({ "were", 0 }), "forged with phoenix fire",
    }));
    add_description(({
       ({ 'p', 0 }), ({ "are", 0 }), "nicked and scratched with use but", ({ "retain", 0 }), ({ 'r', 0, "incredible edge"}),
    }));
    add_description(({
        ({ 'r', 0, "blade" }), "is held in place by an ornamental iyiyik",
    }));
    add_description(({
        "the iyiyik grips the blade firmly within his claws, and is furiously snarling over it's top edge",
    }));
    add_description(({
        "the entire shaft appears to be made of",        
            Description(([
                Description_Type                    : Description_Type_Element_Name,
                Description_Index                   : Element(([
                    Element_Type                    : Material_Uru,
                    Element_Color                   : "blood-red",
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
    weapon()->set_weapon_type(Weapon_Type_Giant_Axe);
    weapon()->set_damage_types(({({"fire","primal"}),({"heat","primal"}),"cutting"}));
    weapon()->set_weapon_skills(([
        Skill_Axe           : 1.0,
        Skill_Massive_Blow  : 1.0,
    ]));
    set_known_value_added(5000);
    add_proportion(([
        Element_Type             : Material_Uru,
        Element_Proportion       : 1.50,
        Element_Color            : "blood-red",
        Element_Flags            : Element_Flag_Secondary,
        Element_Part             : Part_Core,
    ]));
    add_proportion(([
        Element_Type             : Material_Steel,
        Element_Proportion       : 0.50,
        Element_Color            : "blood-red",
    ]));
    add_proportion(([
        Element_Type             : Material_Logos,
        Element_Proportion       : 0.10,
        Element_Flags            : Element_Flag_Secondary,
    ]));
    add_hook(Mod_Inflict_Damage, #'axe_hit);
    add_hook(Do_Equip_Item, #'axe_do_equip);
    add_hook(Do_Unequip_Item, #'axe_do_unequip);
}
