#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

private descriptor attr_mod;
private descriptor skill_mod1;
private descriptor skill_mod2;
private descriptor skill_mod3;
private descriptor trait_mod1;
private descriptor trait_mod2;
private float charge = 0;
private descriptor thought;
private descriptor pulse;
private float charge_level;
private float nearby;

float set_charge(float val) {
    charge = val;
}

float query_charge() {
    return charge;
}

float count_nearby() {
    nearby = to_float(sizeof(user->query_nearby_character_objects())) + 1;
    return nearby;
}

string strike() {
    return random_element(({
        "slice",
        "cut into",
        "stab",
        "impale",
        "lacerate",
        "slash",
    }));
}

float query_charge_level() {
    if(query_charge() < 1000.0) {
        charge_level = 0.0;
    }
    if(query_charge() >= 1000.0 && query_charge() <= 2000.0 ) {
        charge_level = 1.0;
    }
    if(query_charge() >= 2001.0 && query_charge() <= 3000.0 ) {
        charge_level = 2.0;
    }
    if(query_charge() >= 3001.0 && query_charge() <= 5000.0 ) {
        charge_level = 3.0;
    }
    if(query_charge() >= 5001.0 && query_charge() <= 7000.0 ) {
        charge_level = 4.0;
    }
    if(query_charge() >= 7001.0 && query_charge() <= 10000.0 ) {
        charge_level = 5.0;
    }
    if(query_charge() >= 10001.0) {
        charge_level = 6.0;
    }
    return charge_level;
}
    
string query_pulse_type() {
    if(query_charge_level() == 1.0 ) {
        pulse = "a small";
    }
    if(query_charge_level() == 2.0 ) {
        pulse = "an intermediate";
    }
    if(query_charge_level() == 3.0) {
        pulse = "a large";
    }
    if(query_charge_level() == 4.0) {
        pulse = "a huge";
    }
    if(query_charge_level() >= 5.0) {
        pulse = "an enormous";
    }
    return pulse;
}

descriptor moonstone(string color) {
	return Description(([
		Description_Type   : Description_Type_Element_Name,
		Description_Index  : Element(([
			Element_Type   : Material_Moonstone,
			Element_Color  : color,
			Element_Flags  : Element_Flag_Suppress_Color_Name,
		])),
	]));
}

void do_release_charge(mapping args) {
    object moonstone = moonstone("shimmering pink");
    object user = query_user();
    object target = user->query_attacker();
    object room = environment(user);
    user->message(([
        Message_Content     : ({
            ({'s',this_object(),moonstone}),
                ([
                    Message_Content                : ({
                        ({"flash",moonstone}),
                    }),
                    Message_Color                  : "shimmering white",
                ]),
            "and produces",
                ([
                    Message_Content                : ({
                        query_pulse_type(),"wave of pulsing energy",
                    }),
                    Message_Color                  : "shimmering pink",
                ]),
            "that rolls outward from",({ 's', 0, this_object() }),"covering the area.",
        }),
    ]));
    user->query_nearby_character_objects()->message(([
        Message_Content                           : ({
            0, ({"are",0}),"struck by the",
                ([
                    Message_Content               : ({
                        "wave of pulsing energy.",
                    }),
                    Message_Color                 : "shimmering pink",
                ]),
        }),
    ]));
    user->query_nearby_character_objects()->blind_living(query_charge()/256.00, 0, ({"system"}));
    user->query_nearby_character_objects()->do_damage(query_charge()/128, environment(), 0, ({"psionic","qlippotic"}), this_object());
    user->query_nearby_character_objects()->stun_living(query_charge() / 256.00, 0, ({"system","psionic"}));
    user->query_nearby_character_objects()->poison_living(query_charge() / 128.00, query_charge_level() * 16.00, (query_charge_level() * -1.00) + 8.00, False);
    user->query_nearby_character_objects()->add_energy_amount(Energy_Hedonic, query_charge()/64.0);
    user->query_nearby_character_objects()->display(([
        Message_Content                             : ({
            "Waves of paralyzing pleasure course through",({'r',0,"body"}),".",
        }),
        Message_Color                               : "pink",
    ]));
    user->query_nearby_character_objects()->display(([
        Message_Content                             : ({
            "Terrible pain wracks your mind.",
        }),
        Message_Color                               : "shimmering red",
    ]));
    user->add_energy_amount(Energy_Hedonic, (query_charge()/ 64.00));
    user->display(([
        Message_Content                             : ({
            "Waves of paralyzing pleasure course through",({'r',0,"body"}),".",
        }),
        Message_Color                               : "pink",
    ]));
    user->message(([
        Message_Content                             : ({
            ({'s',this_object(),moonstone}),({"turn",moonstone}),
                ([
                    Message_Content                 : ({
                        "shimmering pink",
                    }),
                    Message_Color                   : "shimmering pink",
                ]),
        })
    ]));
    charge = 0.00;
}

status can_release_charge(mapping args) {
    if( query_charge_level() == 0 ) {
        return False;
    }
    return True;
}

void fail_release_charge(mapping args) {
    object moonstone = moonstone("shimmering pink");
    user->message(([
        Message_Content                             : ({
            ({'s',this_object(),moonstone}),
                ([
                    Message_Content                 : ({
                        "flickers dimly.",
                    }),
                    Message_Color                   : "shimmering white",
                ]),
        }),
    ]));
}

void nytelse_do_equip(mapping args) {
    skill_mod1 = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Erotic_Arts,
        Modifier_Amount : 80,
    ]));
    skill_mod2 = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Precision_Strike,
        Modifier_Amount : 60,
    ]));
    skill_mod3 = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Dodge,
        Modifier_Amount : 40,
    ]));
    attr_mod = args["who"]->add_attribute_modifier(([
        Modifier_Index  : Attr_Dex,
        Modifier_Amount : 20,
    ]));
    trait_mod1 = args["who"]->add_trait_modifier(([
        Modifier_Index  : Trait_Sadism,
        Modifier_Amount : 1,
    ]));
    trait_mod1 = args["who"]->add_trait_modifier(([
        Modifier_Index  : Trait_Masochism,
        Modifier_Amount : 2,
    ]));
    args["who"]->display(({
        ({ 's', 0, this_object() }), ({ "hum", this_object() }), "in anticipation.",
    }));
    args["who"]->display(([
        Message_Content     : ({
            "A sense of power rushes through you, bringing with it immense pleasure."
        }),
        Message_Color       : "pink",
    ]));
    args["who"]->add_energy_amount(Energy_Hedonic, 150);
    args["who"]->stun_living(random_range(1, 3), 0, ({"system"}));
    thought = user->add_thought(([
		Thought_Key         : "Nytelse to bestow pleasure",
		Thought_Types       : Thought_Type_Will,
		Thought_Do_Call     : #'do_release_charge,
        Thought_Can_Call    : #'can_release_charge,
        Thought_Fail_Call   : #'fail_release_charge,
	]));
}


void nytelse_do_unequip(mapping args) {
    args["who"]->remove_attribute_modifier(&attr_mod);
    args["who"]->remove_skill_modifier(&skill_mod1);
    args["who"]->remove_skill_modifier(&skill_mod2);
    args["who"]->remove_skill_modifier(&skill_mod3);
    args["who"]->remove_trait_modifier(&trait_mod1);
    args["who"]->remove_trait_modifier(&trait_mod2);
    args["who"]->remove_thought(thought);
}


int nytelse_hit(mapping args) {
    object moonstone = moonstone("shimmering pink");
    object user = query_user();
    object target = args["target"];
    float targ_pleasure = target->query_energy_amount(Energy_Hedonic);
    if(!user || !target || args["deflecting"] || args["ranged"])
        return 0;
    int dam = random(4);
    object room = environment(user);
    switch(dam) {
        case 0 .. 1  :
            user->message(([
                Message_Content             : ({
                    user,({strike(),user}),target,"with",({ 's', 0, this_object()}),"and",'a',
                        ([
                            Message_Content : ({
                                "pulse of pink energy",
                            }),
                            Message_Color   : "shimmering pink",
                        ]),
                    "flows from",({ 's', 0, this_object()}),"and washes over",({'r',target,"body"}),".",
                }),
            ]));
            target->do_damage((5), environment(), -1, ({ "psionic", }), this_object());
            target->add_energy_amount(Energy_Hedonic, 40.00);
            break;
        case 2  :
            user->message(([
                Message_Content             : ({
                    user,({strike(),user}),target,"with",({ 's', 0, this_object()}),"and a",
                        ([
                            Message_Content : ({
                                "stream of pulsing pink energy",
                            }),
                            Message_Color   : "shimmering pink",
                        ]),
                    "flows from",target,"into",({ 's', 0, this_object()}),
                }),
                Message_Senses              : Message_Sense_Astral,
            ]));
            charge = charge + targ_pleasure;
            target->remove_energy_amount(Energy_Hedonic, targ_pleasure);
            target->remove_energy_amount(Energy_Spiritual, 15.00);
            user->add_energy_amount(Energy_Spiritual, 15.00);
            break;       
        case 3  :
            target->add_trait_modifier(([
                Modifier_Index      : Trait_Masochism,
                Modifier_Amount     : 6,
                Modifier_Duration   : 15,
            ]));
            if(query_charge_level() == 1.0) {
                user->message(({({'s',this_object(),moonstone}),"{{flickering dark pink}flickers dimly}."}));
            }
            if(query_charge_level() == 2.0) {
                user->message(({({'s',this_object(),moonstone}),"{{shimmering pink}flickers}."}));
            }
            if(query_charge_level() == 3.0) {
                user->message(({({'s',this_object(),moonstone}),"{{dark pink-and-pink-and-pink-and-pink-and-dark pink-and-pink-and-pink-and-dark pink}shimmers}."}));
            }
            if(query_charge_level() == 4.0) {
                user->message(({({'s',this_object(),moonstone}),"{{pink-and-white-and-pink}flashes}."}));
            }
            if(query_charge_level() == 5.0) {
                user->message(({({'s',this_object(),moonstone}),"{{shimmering white}flashes and shines}."}));
            }
            if(query_charge_level() == 6.0) {
                user->message(({({'s',this_object(),moonstone}),"{{bright white}flashes and shines with blinding radiance}."}));
                int blind = random(3);
                    if(blind == 0) {
                        target->blind_living(random_range(1, 3), 0, ({"photonic"}));
                    }
            }
        break;
    }
    return dam;
}

void configure() {
    ::configure();
    alter_identity(([
        Identity_Name           : "Nytelse",
        
        Identity_Flags          : Identity_Flag_Proper,
    ]));
    set_identify_skills(([
        Skill_Qlippotic_Lore    : 90,
    ]));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), 'a', "beautiful and deadly looking",
        Description(([
            Description_Type    : Description_Type_Element_Name,
            Description_Content : Description(Description_Type_Weapon_Type_Name),
            Description_Flags   : Description_Flag_Adjective,
        ])),
    }));
    add_description(({
        ({'r',0,"hilt"}),"is comfortable looking and is set with a large",moonstone("shimmering pink"),
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }),({'p',0}),"as Nytelse, a weapon thought to contain the soul of a succubus",
    }));
    add_known_description(({
        "it is said that it uses pleasure to bring its victims life to an end",
    }));
    set_unique(True);
    set_craft(Craft_Unearthly);
    weapon()->set_weapon_type(Weapon_Type_Dagger);
    weapon()->set_damage_types(({ "piercing", "qlippotic", "spirit" }));
    set_known_value_added(5000);
    weapon()->set_penetration(0);
    weapon()->set_weapon_skills(([
                Skill_Erotic_Arts       : 1.0,
                Skill_Precision_Strike  : 1.0,
                Skill_Martial_Arts      : 1.0,
    ]));
    add_proportion(([
        Element_Type             : Material_Mithril,
        Element_Proportion       : 1.0,
        Element_Color            : "shimmering black",
    ]));
    add_proportion(([
        Element_Type             : Material_Qlippotam,
        Element_Proportion       : 0.01,
        Element_Part             : Part_Aura,
    ]));
    add_proportion(([
        Element_Type             : Material_Moonstone,
        Element_Proportion       : 0.1,
        Element_Part             : Part_Inset,
        Element_Color            : "shimmering pink",
        Element_Flags            : Element_Flag_Secondary,
    ]));
    add_hook(Mod_Inflict_Damage, #'nytelse_hit);
    add_hook(Do_Equip_Item, #'nytelse_do_equip);
    add_hook(Do_Unequip_Item, #'nytelse_do_unequip);
}
