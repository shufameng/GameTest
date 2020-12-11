#ifndef SFMUNIT_H
#define SFMUNIT_H

#include <string>
#include <list>

// HealthPoint, HealthRecovery, ManaPoint, ManaRecovery, Armor, AttackPoint, AttackSpeed

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;

//
class SFMObject {
public:
    SFMObject() {

    }

    virtual ~SFMObject() {

    }

    unsigned long handleId() const {
        return (unsigned long)this;
    }

};

//
class SFMDamage {
public:
    enum DamageType {
        NormalDamage = 0,
        MagicDamage
    };
    DamageType type;
    double value;
};

//
class SFMAbility : public SFMObject {
public:
    enum AbilityType {
        PositiveAbility = 0,
        PassiveAbility
    };

    AbilityType type;
    std::string name;
    std::string toolTip;
    int manaCost;
};

//
class SFMPassiveAbilityEffect {
public:
    enum PassiveAbilityEffectType {
        IncreaseMaxHealthPoint = 0,
        IncreaseHealthRecovery,
        IncreaseMaxManaPiont,
        IncreaseManaRecovery,
        IncreaseArmor,
        IncreaseAttackPoint,
        IncreaseAttackSpeed,
        ChanceToCriticalStrike,
        ChanceToEvade,
        ChanceToBash
    };

    PassiveAbilityEffectType type;
    union {
        int int_var;
        double double_var;
    } value;
};

//
class SFMPositiveAbility : public SFMAbility {
public:
};

//
class SFMPassiveAbility : public SFMAbility {
public:
};

//
class SFMBuff {
public:

    double duration;
};

//
class SFMItem {
public:
};

class SFMAbility;
class SFMBuff;
class SFMDebuff;
class SFMDamage;

//
class SFMUnit : public SFMObject
{
public:
    SFMUnit();

    void addAbility( SFMAbility *ability ) {
        if ( !ability )
            return;

        bool alreadyInList = false;
        for ( std::list<SFMAbility*>::const_iterator iter = abilityList.begin(); iter != abilityList.end(); ++ iter ) {
            if ( ability->handleId() == (*iter)->handleId() ) {
                alreadyInList = true;
                break;
            }
        }
        if ( !alreadyInList ) {
            abilityList.push_back(ability);
        }
    }

    void removeAbility(SFMAbility *ability);

    std::string name;
    int baseHealthPoint;
    int baseHealthRecovery;
    int baseManaPoint;
    int baseManaRecovery;
    int baseArmor;
    int baseMoveSpeed;
    int baseAttackPoint;
    double baseAttackInterval;
    std::list<SFMAbility*> abilityList;
    std::list<SFMBuff*> buffList;
    std::list<SFMItem*> itemList;
};

#endif // SFMUNIT_H
