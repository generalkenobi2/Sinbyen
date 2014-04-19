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
private descriptor skein;
private descriptor crackle;
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

float query_charge_level() {
    if(query_charge() < 1000) {
        charge_level = 0.0;
    }
    if(query_charge() >= 1000.00 && query_charge() < 2000.00 ) {
        charge_level = 1.0;
    }
    if(query_charge() > 2001.00 && query_charge() < 3000.00 ) {
        charge_level = 2.0;
    }
    if(query_charge() > 3001.00 && query_charge() < 5000.00 ) {
        charge_level = 3.0;
    }
    if(query_charge() > 5001.00 && query_charge() < 7000.00 ) {
        charge_level = 4.0;
    }
    if(query_charge() > 7001.00 && query_charge() < 10000.00 ) {
        charge_level = 5.0;
    }
    if(query_charge() > 10001.00) {
        charge_level = 6.0;
    }
    return charge_level;
}
    
string query_skein_type() {
    if(query_charge_level() == 1.0 ) {
        skein = "a small";
    }
    if(query_charge_level() == 2.0 ) {
        skein = "an intermediate";
    }
    if(query_charge_level() == 3.0) {
        skein = "a large";
    }
    if(query_charge_level() == 4.0) {
        skein = "a huge";
    }
    if(query_charge_level() == 5.0) {
        skein = "an enormous";
    }
    if(query_charge_level() == 6.0) {
        skein = "an enormous swirling";
    }
    return skein;
}
string query_skein_crackles() {
    if(query_charge_level() == 6.0) {
        crackle = "crackling";
    }
    if(query_charge_level() < 6.0) {
        crackle = "";
    }
    return crackle;
}
    

void do_release_charge(mapping args) {
    object user = query_user();
    object target = user->query_attacker();
    object room = environment(user);
    user->message(({'p',({'s',this_object(),Description(([
                                Description_Type   : Description_Type_Element_Name,
                                Description_Index  : Element(([
                                    Element_Type   : Material_Bloodstone,
                                    Element_Color  : "shimmering violet",
                                    Element_Flags  : Element_Flag_Suppress_Color_Name,
                                ])),
                            ])),
                        }),
                    "turn a {{white}bright white} and produce",'j',"{{shimmering violet}",query_skein_type(),
                    Description(([
                        Description_Type        : Description_Type_Viewer_Condition,
                        Description_Index       : ([
                            Condition_Type_Code : Condition_Type_Hearing,
                        ]),
                        Description_Content     : query_skein_crackles(),
                    ])),
                    "skein of translucent energy} that lashes out at",
                    target, "wrapping around", ({ 'o', target }),"numerous times",
    }));
    target->do_damage(query_charge() / 64.00, environment(), -1, ({"force","cutting",({"extropy","qlippotic"})}), this_object());
    user->message(({"A {{shimmering bright white}surge of energy} floods up the{{shimmering violet}",query_skein_type(),
                    Description(([
                        Description_Type        : Description_Type_Viewer_Condition,
                        Description_Index       : ([
                            Condition_Type_Code : Condition_Type_Hearing,
                        ]),
                        Description_Content     : query_skein_crackles(),
                    ])),
                    "skein of translucent energy} and into",target,
    }));
    target->do_damage(query_charge() / 32.00, environment(), -1, ({"system",({"spirit","extropy","qlippotic"})}), this_object());
    user->message(({"The {{shimmering bright white}surge of energy} {{fiery yellow}explodes outward} from",target,", bathing the area in athe area in a {{shimmering bright violet}blinding violet mist}"}));
    user->query_nearby_character_objects()->blind_living(query_charge_level()), 0, ({"photonic"});
    user->query_nearby_character_objects()->stun_living(query_charge_level() / 2, 0, ({"system","photonic"}));
    user->query_nearby_character_objects()->add_energy_amount(Energy_Algetic, (query_charge() / 64.00) / count_nearby());
    user->add_energy_amount(Energy_Algetic, (query_charge() / 64.00) / count_nearby());
    user->query_nearby_character_objects()->do_damage(query_charge() / 256.00, environment(), -1, ({"system"}), this_object());
    user->query_nearby_character_objects()->display(({"{{shimmering dark red}Searing pain floods through",({'r',0,"body"}),".}"}));
    user->do_damage(query_charge() / 256.00, environment(), -1, ({"system"}), this_object());
    user->display(({"{{shimmering dark red}Searing pain floods through",({'r',0,"body"}),".}"}));
    user->message(({'j',"The {{shimmering violet}",query_skein_type(),
                    Description(([
                        Description_Type        : Description_Type_Viewer_Condition,
                        Description_Index       : ([
                            Condition_Type_Code : Condition_Type_Hearing,
                        ]),
                        Description_Content     : query_skein_crackles(),
                    ])),
                    "skein of translucent energy} separates from",({ 's', 0, this_object() }),
                    "in a flash of {{shimmering violet}violet light} and plunges itself deep into",({'r',target,"body"}),
    }));
    target->do_damage(query_charge() / 64.00, environment(), -1, ({"cutting","system",({"extropy","qlippotic"})}), this_object());
    user->message(({'p',({'s',this_object(),Description(([
                                Description_Type   : Description_Type_Element_Name,
                                Description_Index  : Element(([
                                    Element_Type   : Material_Bloodstone,
                                    Element_Color  : "shimmering bright white",
                                    Element_Flags  : Element_Flag_Suppress_Color_Name,
                                ])),
                            ])),
                        }),    
                    "turns {{shimmering violet}shimmering violet}.",
    }));
    charge = 0.00;
}

status can_release_charge(mapping args) {
    object user = query_user();
    object target = user->query_attacker();
    if( query_charge_level() == 0 || target == 0 ) {
        return False;
    }
    return True;
}

void fail_release_charge(mapping args) {
    user->message(({({'s',this_object(),Description(([
                                Description_Type   : Description_Type_Element_Name,
                                Description_Index  : Element(([
                                    Element_Type   : Material_Bloodstone,
                                    Element_Color  : "shimmering dark violet",
                                    Element_Flags  : Element_Flag_Suppress_Color_Name,
                                ])),
                            ])),
                        }),
                    "{{flickering white}flickers dimly}."}));    
}

void nyeri_do_equip(mapping args) {
    skill_mod1 = args["who"]->add_skill_modifier(([
        Modifier_Index  : Skill_Torture,
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
        Modifier_Amount : 2,
    ]));
    trait_mod1 = args["who"]->add_trait_modifier(([
        Modifier_Index  : Trait_Masochism,
        Modifier_Amount : 1,
    ]));
    args["who"]->display(({
        ({ 's', 0, this_object() }), ({ "spread", this_object() }), ({'l', this_object()}),"open, eagerly awaiting use",
    }));
    args["who"]->display(({
        "{{pink}Waves of pain rush through you, bringing with it a surge of energy that leaves you feeling more agile.}",
    }));
    args["who"]->add_energy_amount(Energy_Algetic, 100);
    args["who"]->stun_living(random_range(1, 3), 0, ({"system"}));
    thought = user->add_thought(([
		Thought_Key         : "Nyeri to release her pain",
		Thought_Types       : Thought_Type_Will,
		Thought_Do_Call     : #'do_release_charge,
        Thought_Can_Call    : #'can_release_charge,
        Thought_Fail_Call   : #'fail_release_charge,
	]));
}


void nyeri_do_unequip(mapping args) {
    args["who"]->remove_attribute_modifier(&attr_mod);
    args["who"]->remove_skill_modifier(&skill_mod1);
    args["who"]->remove_skill_modifier(&skill_mod2);
    args["who"]->remove_skill_modifier(&skill_mod3);
    args["who"]->remove_trait_modifier(&trait_mod1);
    args["who"]->remove_trait_modifier(&trait_mod2);
    args["who"]->remove_thought(thought);
}


int tessen_hit(mapping args) {
    object user = query_user();
    object target = args["target"];
    float targ_pain = target->query_energy_amount(Energy_Algetic);
    if(!user || !target || args["deflecting"] || args["ranged"])
        return 0;
    int dam = random(4);
    object room = environment(user);
    switch(dam) {
        case 0 .. 1  :
            user->message(({"Several of",({ 'r', this_object(), "razor blades"}),"break off in",({'r',target,"flesh"})}));
            user->message(({({'r',this_object(),"broken blades"}),"regrow immediately."}));
            target->do_damage((5), environment(), -1, ({ "cutting" }), this_object());
            target->add_energy_amount(Energy_Algetic, 30.00);
            break;
        case 2  :
            user->message(({"As", user, ({ "make", user }), "contact with", target, "{{shimmering dark violet}a jagged skein of violet energy} rushes from",target,"to",({ 's', 0, this_object()}),}));    
            charge = charge + targ_pain;
            target->remove_energy_amount(Energy_Algetic, targ_pain);
            break;       
        case 3  :
            if(query_charge_level() == 1.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{flickering dark violet}flickers dimly}."}));
            }
            if(query_charge_level() == 2.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{shimmering violet}flickers}."}));
            }
            if(query_charge_level() == 3.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{dark violet-and-pink-and-pink-and-pink-and-dark violet-and-pink-and-pink-and-dark violet}shimmers}."}));
            }
            if(query_charge_level() == 4.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{pink-and-white-and-pink}flashes}."}));
            }
            if(query_charge_level() == 5.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{shimmering white}flashes and shines}."}));
            }
            if(query_charge_level() == 6.0) {
                user->message(({({'s',this_object(),Description(([
                                                                            Description_Type   : Description_Type_Element_Name,
                                                                            Description_Index  : Element(([
                                                                                Element_Type   : Material_Bloodstone,
                                                                                Element_Color  : "shimmering dark violet",
                                                                                Element_Flags  : Element_Flag_Suppress_Color_Name,
                                                                            ])),
                                                                        ])),
                                                    }),"{{bright white}flashes and shines with blinding radiance}."}));
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
        Identity_Name           : "Nyeri",
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
        ({'r',0,"ribs"}),"are razor tipped and each is set with a large",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Bloodstone,
                    Element_Color                       : "shimmering violet",
                ])),
            ])),
    }));
    add_known_description(({
        'v', ({ "recognize", 'v' }),({'p',0}),"as Nyeri, a weapon thought to contain the soul of a demon",
    }));
    add_known_description(({
        "it is said that its only purpose is to inflict incredible pain and agony",
    }));
    set_unique(True);
    set_craft(Craft_Unearthly);
    weapon()->set_weapon_type(Weapon_Type_Tessen);
    weapon()->set_damage_types(({ "cutting", "qlippotic", "spirit" }));
    set_known_value_added(5000);
    weapon()->set_penetration(0);
    weapon()->set_weapon_skills(([
                Skill_Torture           : 1.0,
                Skill_Precision_Strike  : 1.0,
                Skill_Martial_Arts      : 1.0,
    ]));
    add_proportion(([
        Element_Type             : Material_Steel,
        Element_Proportion       : 1.0,
        Element_Color            : "shimmering black",
    ]));
    add_proportion(([
        Element_Type             : Material_Qlippotam,
        Element_Proportion       : 0.01,
        Element_Part             : Part_Aura,
    ]));
    add_proportion(([
        Element_Type             : Material_Bloodstone,
        Element_Proportion       : 0.1,
        Element_Part             : Part_Inset,
        Element_Color            : "shimmering violet",
        Element_Flags            : Element_Flag_Secondary,
    ]));
    add_hook(Mod_Inflict_Damage, #'tessen_hit);
    add_hook(Do_Equip_Item, #'nyeri_do_equip);
    add_hook(Do_Unequip_Item, #'nyeri_do_unequip);
}
