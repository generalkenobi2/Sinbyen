#include <item.h>
#include <Lobaan_a_Aislynn.h>
#include <senses.h>
#include <speech.h>
#include <languages.h>
#include <language.h>
#include <interval.h>
#include <spell_step.h>
#include <usage.h>
#include <realtime.h>
#include <damage_types.h>

inherit "/std/item";

status active;

string aislynn_s_goggles_query_writing_description(object who) {
    status recognizes_anglic = who->query_recognize_language(Skill_Anglic);
    if(recognizes_anglic)
        return self_color("unholy fire", 0, "Anglic writing");
    else
        return self_color("unholy fire", Language(Skill_Anglic)->query_language_description(), "writing");
}

void aislynn_s_goggles_hud(object who, string what) {
    descriptor speech = Speech(([
        Speech_Speaker                                  : this_object(),
        Speech_Language                                 : Skill_Anglic,
        Speech_Via                                      : Speech_Medium_Written,
        Speech_Original_Message                         : what,
        Speech_Modified_Message                         : what,
    ]));
    string text = who->language_processed_message(speech, Comp_Read);
    status recognizes_anglic	= who->query_recognize_language(Skill_Anglic);
    if(!sizeof(text)) {
        who->display(([
            Message_Content                             : ({
                "the", aislynn_s_goggles_query_writing_description(who), "on the",
                Description(([
                    Description_Type                    : Description_Type_Element_Name,
                    Description_Index                   : find_element(Material_Imire),
                ])),
                "of", ({ 'r', 0, "goggles" }), "flickers and changes to read something incomprehensible to", ({ 'o', 0 }),
            }),
            Message_Senses                              : Message_Sense_Visual,
        ]));
    } else {
        who->display(([
            Message_Content                             : ({
                "the", aislynn_s_goggles_query_writing_description(who), "on the",
                Description(([
                    Description_Type                    : Description_Type_Element_Name,
                    Description_Index                   : find_element(Material_Imire),
                ])),
                "of", ({ 'r', 0, "goggles" }), "flickers and changes to read: {{unholy fire}[" +
                text
                + "]}"
            }),
            Message_Senses                              : Message_Sense_Visual,
        ]));
    }
}

void aislynn_s_goggles_analyze_area(object who, object where) {
    string array output = ({});
    int array terrains = where->query_terrains();
    if(sizeof(terrains)) {
        string item = "terrain: ";
        item += list_array(map(terrains, (:
            Terrain($1)->query_terrain_name()
        :)));
        output += ({ item });
    }
    int array fieldcraft_skills = where->query_fieldcraft_skills();
    if(sizeof(fieldcraft_skills)) {
        string item = "relevant fieldcraft: ";
        item += list_array(map(fieldcraft_skills, (:
            Skill($1)->query_skill_name()
        :)));
        output += ({ item });
    }
    if(sizeof(output))
        aislynn_s_goggles_hud(who, implode(output, "; "));
}

void aislynn_s_goggles_analyze_item(object who, object what) {
    if(what == this_object())
        return;
    string array output = ({});
    if(what->query_armour_instantiated()) {
        string item = "absorption: ";
        item += to_string(what->armour()->query_absorption());
        output += ({ item });
    }
    if(what->query_weapon_instantiated()) {
        string damage = "damage: ";
        damage += to_string(round(what->weapon()->query_damage(), 0.01));
        string penetration = "penetration: ";
        penetration += to_string(round(what->weapon()->query_penetrate(), 0.01));
        string agonize = "agonize: ";
        agonize += to_string(round(what->weapon()->query_agonize(), 0.01));
        string stun = "stun: ";
        stun += to_string(round(what->weapon()->query_stun(), 0.01));
        output += ({ damage, penetration, agonize, stun });
        if(what->weapon()->query_discharges()) {
            string dis_damage = "discharge damage: ";
            dis_damage += to_string(round(what->weapon()->query_discharge_damage(), 0.01));
            string dis_penetration = "discharge penetration: ";
            dis_penetration += to_string(round(what->weapon()->query_discharge_penetrate(), 0.01));
            string dis_agonize = "discharge agonize: ";
            dis_agonize += to_string(round(what->weapon()->query_discharge_agonize(), 0.01));
            string dis_stun = "discharge stun: ";
            dis_stun += to_string(round(what->weapon()->query_discharge_stun(), 0.01));
            output += ({ dis_damage, dis_penetration, dis_agonize, dis_stun });
        }
    }
    if(sizeof(output))
        aislynn_s_goggles_hud(who, implode(output, "; "));
}

void aislynn_s_goggles_analyze_character(object who, object character) {
    int offensive_threat = 0;
    int defensive_threat = 0;
    int high_attack = 0;
    int high_damage = 0;
    int array limbs = character->query_attacking_limbs() || ({});
    object array weapons = character->query_wielded_weapons() || ({});
    foreach(object weapon : weapons) {
        int attack_rating = weapon->weapon()->query_attack_rating(character->query_attacker());
        if(attack_rating > high_attack)
            high_attack = attack_rating;
        int damage_rating = weapon->weapon()->query_damage_rating(character->query_attacker());
        if(damage_rating > high_damage)
            high_damage = damage_rating;
        int deflect_rating = weapon->weapon()->query_deflect_rating(character->query_attacker());
        if(deflect_rating > defensive_threat)
            defensive_threat = deflect_rating;
    }
    foreach(int limb : limbs) {
        int attack_rating = character->query_attack_rating(limb, character->query_attacker());
        if(attack_rating > high_attack)
            high_attack = attack_rating;
        int damage_rating = character->query_damage_rating(limb, character->query_attacker());
        if(damage_rating > high_damage)
            high_damage = damage_rating;
        int deflect_rating = character->query_deflect_rating(limb, character->query_attacker());
        if(deflect_rating > defensive_threat)
            defensive_threat = deflect_rating;
    }
    offensive_threat = high_attack + high_damage;
    int dodge_rating = character->query_dodge_rating(character->query_attacker());
    dodge_rating += character->query_passive_defense_rating(character->query_attacker());
    if(dodge_rating > defensive_threat)
        defensive_threat = dodge_rating;
    float high_abs = 0.0;
    foreach(int limb : character->existing_limbs(Existing_Limb_Functional)) {
        float abs = 0.0;
        mixed array prof = character->query_absorption_profile(({ limb }));
        foreach(mixed item : prof)
            if(objectp(item[1]))
                abs += item[1]->armour()->query_effective_absorption();
            else
                abs += item[1];
        if(abs > high_abs)
            high_abs = abs;
    }
    defensive_threat += round(high_abs) * 200;
    string array types = filter(Daemon_Damage_Types->query_damage_types(), (: $1->query_damage_type_class() != Damage_Class_System :))->query_damage_type_name();
    foreach(string type : types)
        defensive_threat += round(character->query_resistance(type) * Damage_Type(type)->query_damage_type_resistance_value()) * 2;
    string offense = "offensive threat level: " + to_string(offensive_threat);
    string defense = "defensive threat level: " + to_string(defensive_threat);
    string array output = ({ offense, defense });
    string array harm_skills = map(m_indices(character->query_harm_skills()), (:Skill($1)->query_skill_name() :));
    if(sizeof(harm_skills))
        output += ({
            "threat management domains: " + implode(harm_skills, ", ")
        });
    aislynn_s_goggles_hud(who, implode(output, "; "));
}

void aislynn_s_goggles_analyze_damage(object who, descriptor attack) {
    float damage = Attack_Total_Damage(attack);
    unless(damage >= 0.5)
        return;
    string output = "attack damage: ";
    output += to_string(round(damage, 0.01));
    aislynn_s_goggles_hud(who, output);
}

void aislynn_s_goggles_at_area_sense(mapping args) {
    int sense = args["sense"];
    object who = args["who"];
    object where = args["area"];
    unless(where && who && Sense(sense)->query_sense_message_sense() == Message_Sense_Visual)
        return;
    aislynn_s_goggles_analyze_area(who, where);
}

void aislynn_s_goggles_do_look(mapping args) {
    object who = args["who"];
    object what = args["what"];
    unless(objectp(what))
        return;
    if(!what->is_character())
        aislynn_s_goggles_analyze_item(who, what);
    else
        aislynn_s_goggles_analyze_character(who, what);
}

void aislynn_s_goggles_at_message_received(mapping args) {
    descriptor message = args["message"];
    descriptor attack = Is_Message(message) && Message_Query_Info(message, "System_Attack");
    unless(Is_Attack(attack))
        return;
    unless(Attack_Flag_Check(attack, Attack_Flag_Successful))
        return;
    unless(Message_Sense_Check(message, Message_Sense_Visual))
        return;
    object who = args["to"];
    unless(who)
        return;
    unless(funcall(Sense("visual primary")->query_sense_usability_rule(), who))
        return;
    aislynn_s_goggles_analyze_damage(who, attack);
}

varargs float aislynn_s_goggles_query_cost(object who) {
    who ||= query_user();
    if(!who)
        return 50.0;
    float min = Spell_Step_Difficulty_Minimum_Rating(Spell_Step_Difficulty_Easy, Spell_Step_Importance_None);
    float max = Spell_Step_Difficulty_Maximum_Rating(Spell_Step_Difficulty_Hard, Spell_Step_Importance_None);
    float cost = scale_conversion(who->query_average_effective_skill(({ Skill_Symbology, Skill_Mathematics }), ({})), min, max, 50.0, 4.0);
    return cost;
}

int aislynn_s_goggles_power_cycle() {
    unless(active)
        return Interval_Terminate;
    object who = query_user();
    unless(who)
        return Interval_Terminate;
    float cost = aislynn_s_goggles_query_cost(who);
    who->add_spell_points(-fuzz(cost));
    string description;
    if(cost >= 45)
        description = "copious amounts";
    else if(cost >= 20)
        description = "large amounts";
    else if(cost >= 10)
        description = "substantial amounts";
    else if(cost >= 5)
        description = "some";
    else
        description = "a little of";
    if(!random(10) && who->query_skill(Skill_Divination) > random(600))
        who->display(([
            Message_Content                             : ({
                0, ({ "sense", 0 }), description, "of",
                ({ 'r', 0, "spiritual energy" }), "flowing out through", ({ 'r', 0, query_current_limbs_bound() }),
                "into", this_object(),
            }),
            Message_Flags                               : Message_Sense_Spiritual,
            Message_Color                               : "status: risk",
        ]));
    return 0;
}

varargs status aislynn_s_goggles_can_activate(object who) {
    if(active)
        return False;
    who ||= query_user();
    unless(who)
        return False;
    int usage = who->query_how_used(this_object());
    unless(usage == Usage_Wear)
        return False;
    int array bound = query_current_limbs_bound(who);
    foreach(int limb : bound)
        if(who->query_limb_provides_vision(limb))
            return True;
    return False;
}

varargs status aislynn_s_goggles_can_deactivate(object who) {
    who ||= query_user();
    unless(who)
        return False;
    unless(active)
        return False;
    return True;
}

varargs void aislynn_s_goggles_do_activate(object who) {
    who ||= query_user();
    who->add_hook(Do_Look, #'aislynn_s_goggles_do_look);
    who->add_hook(At_Area_Sense, #'aislynn_s_goggles_at_area_sense);
    who->add_hook(At_Message_Received, #'aislynn_s_goggles_at_message_received);
    who->display(([
        Message_Content                                 : ({
            aislynn_s_goggles_query_writing_description(who),
            "appears in the corner of the",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : find_element(Material_Imire),
            ])),
            "of", ({ 's', 0, "goggles" }), ", at the edge of", ({ 'r', 0, "visual focus" }),
            ", flickering and changing too rapidly to read",
        }),
        Message_Senses                                  : Message_Sense_Visual,
    ]));
    aislynn_s_goggles_hud(who, "bootstrap successful");
    who->message(([
        Message_Content                                 : ({
            'a', self_color("unholy fire", "tiny flickering", "glow"), "appears in the corner of the",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : find_element(Material_Imire),
                Description_Content                     : ({ "left", "lens" }),
            ])),
            "of", ({ 's', 0, "goggles" }),
        }),
        Message_Senses                                  : Message_Sense_Visual,
        Message_Exclude                                 : who,
    ]));
    active = True;
    aislynn_s_goggles_power_cycle();
    Interval_Set(#'aislynn_s_goggles_power_cycle, fuzz(Time_Second * 15));
}

varargs void aislynn_s_goggles_do_deactivate(object who) {
    who ||= query_user();
    who->remove_hook(Do_Look, #'aislynn_s_goggles_do_look);
    who->remove_hook(At_Area_Sense, #'aislynn_s_goggles_at_area_sense);
    who->remove_hook(At_Message_Received, #'aislynn_s_goggles_at_message_received);
    aislynn_s_goggles_hud(who, "powering down");
    who->display(([
        Message_Content                                 : ({
            aislynn_s_goggles_query_writing_description(who),
            "flickering in the corner of the",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : find_element(Material_Imire),
            ])),
            "of", ({ 's', 0, "goggles" }), "flickers one final time and then blinks off",
        }),
        Message_Senses                                   : Message_Sense_Visual,
    ]));
    who->message(([
        Message_Content                                 : ({
            "the", self_color("unholy fire", "tiny flickering", "glow"), "in the corner of the",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : find_element(Material_Imire),
                Description_Content                     : ({ "left", "lens" }),
            ])),
            "of", ({ 's', 0, "goggles" }), "blinks and vanishes",
        }),
        Message_Senses                                  : Message_Sense_Visual,
        Message_Exclude                                 : who,
    ]));
    active = False;
    Interval_Remove(#'aislynn_s_goggles_power_cycle);
}

void aislynn_s_goggles_do_unequip_item(mapping args) {
    object who = args["who"];
    if(aislynn_s_goggles_can_deactivate(who))
        aislynn_s_goggles_do_deactivate(who);
}

status aislynn_s_goggles_flip_command(string arg) {
    string on;
    object who = this_player();
    if(arg == "switch") {
        who->display(({
            "flip the switch on what?"
        }));
        return True;
    }
    unless(arg && sscanf(arg, "switch on %s", on) == 1)
        return False;
    object what = who->locate_name(on);
    unless(what == this_object())
        return False;
    unless(environment() == who) {
        who->display(({
            who, ({ "must", who }), "be carrying", this_object(), "to do that",
        }));
        return True;
    }
    unless(query_user() == who) {
        who->display(({
            who, ({ "must", who }), "be wearing", this_object(), "to do that",
        }));
        return True;
    }
    descriptor manip = Manipulator_Select(who, Manipulator_Flag_Prehensile | Manipulator_Flag_Kinetic | Manipulator_Flag_Translocative, ([
        "custom command"                                : this_object()
    ]));
    unless(manip) {
        who->display(({
            0, ({ "have", 0 }), "no functioning manipulatory limbs or other "            
            "capabilities", ({ 'p', 0 }), "could use to attempt that"
        }));
        return True;
    }
    who->message(([
        Message_Content                                 : ({
            0, ({ "flip", 0 }), "the switch on the side of", ({ 'r', 0, this_object() }), "with",
            ({ 'r', 0, Manipulator_Represent(manip, who) }),
        }),
        Message_Senses                                  : Message_Sense_Visual | Message_Sense_Tactile_For_Participants,
        Message_Alternate                               : ([
            Message_Content                             : ({
                0, ({ "hear", 0 }), "a soft click",
            }),
            Message_Senses                              : Message_Sense_Auditory,
            Message_Flags                               : Message_Flag_Resubjectify_To_Viewer,
        ]),
    ]));
    if(aislynn_s_goggles_can_activate(who))
        aislynn_s_goggles_do_activate(who);
    else if(aislynn_s_goggles_can_deactivate(who))
        aislynn_s_goggles_do_deactivate(who);
    return True;
}

descriptor aislynn_s_goggles_lens_machinery_description() {
    if(!active)
        return ({
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : ([
                    Element_Part                        : Part_Core,
                ]),
                Description_Content                     : ({ "intricate", "wiring and machinery" }),
            ])),
            "is barely visible around the periphery of the left lens",
        });
    else
        return ({
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : ([
                    Element_Part                        : Part_Core,
                ]),
                Description_Content                     : ({ "intricate", "wiring and machinery" }),
            ])),
            "is barely visible around the periphery of the left lens, and", 'a',
            self_color("unholy fire", "tiny flickering", "glow"),
            "is visible on the corner of the surface of the",
            Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Material_Imire,
            ])),
        });
}

void configure() {
    ::configure();
    alter_identity(Identity_Code, "Kenobi's goggles");
    set_unique(True);
    armour()->set_armour_type(Armour_Type_Goggles);
    armour()->set_armour_style(Armour_Style_Simple);
    armour()->set_race("chaosborn");
    set_craft(Craft_Exquisite);
    set_identify_skills(([
        Skill_Carousing                                 : 75,
        Skill_Legend_Lore                               : 75,
        Skill_Rune_Lore                                 : 115,
    ]));
    add_description(({
        "this is", 'a', Description(Description_Type_Armour_Type_Name), "composed of", 
        Description(([
            Description_Type                            : Description_Type_Element_Name,
            Description_Index                           : Material_Imire,
            Description_Content                         : "lenses",
        ])),
        "set into",
        Description(([
            Description_Type                            : Description_Type_Element_Name,
            Description_Index                           : Material_Steel,
            Description_Content                         : ({ "two", "rims" }),
        ])),
        "and held together with", 'a',
        Description(([
            Description_Type                            : Description_Type_Element_Name,
            Description_Index                           : Material_Leather,
            Description_Content                         : ({ "thick band of", }),
        ])),
    }));
    add_description(({
        "There is", 'a',
        Description(([
            Description_Type                            : Description_Type_Element_Name,
            Description_Index                           : ([
                Element_Type                            : Material_Silver,
                Element_Part                            : Part_Inset,
            ]),
            Description_Content                         : ({ "small", "switch" }),
        ])),
        "on the side of the left rim",
        ", and a small symbol resembling a stylized feather etched into the opposite side of the right rim",
    }));
    add_description(({
        "despite the leather and metal looking a bit weathered, the overall craftsmanship is",
        Description(Description_Type_Craftsmanship_Name),
    }));
    add_description(#'aislynn_s_goggles_lens_machinery_description);
    add_known_description(({
        "these are Aislynn's goggles"
    }));
    add_known_description(({
        "it is said that Aislynn offloaded a significant portion of her vast knowledge -- both her tremendous learning and her particular memories",
        "and experiences -- into these goggles, and further enhanced them with symbological-mathematical enchantments and mechanisms",
    }));
    add_known_description(({
        "the end result is a pair of lenses that offers strange, sometimes undecipherable, but often invaluable insights into the workings of the universe",
    }));
    add_proportion(([
        Element_Type                                    : Material_Imire,
        Element_Color                                   : "white",
        Element_Proportion                              : 0.20,
        Element_Part                                    : Part_Inset,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Steel,
        Element_Proportion                              : 0.40,
        Element_Part                                    : Part_Rim,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Leather,
        Element_Proportion                              : 0.60,
        Element_Color                                   : "brown",
        Element_Part                                    : Part_Wrap,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Silver,
        Element_Proportion                              : 0.03,
        Element_Part                                    : Part_Inset,
        Element_Flags                                   : Element_Flag_Secondary,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Silver,
        Element_Proportion                              : 0.03,
        Element_Part                                    : Part_Core,
        Element_Form                                    : Form_Machinery,
        Element_Flags                                   : Element_Flag_Secondary,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Xorakas,
        Element_Proportion                              : 2.00,
        Element_Flags                                   : Element_Flag_Suppress_Override_Color,
    ]));
    add_proportion(([
        Element_Type                                    : Material_Logos,
        Element_Proportion                              : 0.05,
    ]));
    set_unique_allow_permanent_keep(True);
    set_keep_cost(Keep_Cost_Unique_High);
    set_known_value_added(15000);
    set_global_rarity(Rarity_Very_Exotic);
    add_hook(Do_Unequip_Item, #'aislynn_s_goggles_do_unequip_item);
}

string query_personal_item_owner() {
    return "krash";
}

void init() {
    ::init();
    add_action("aislynn_s_goggles_flip_command", "flip");
}
