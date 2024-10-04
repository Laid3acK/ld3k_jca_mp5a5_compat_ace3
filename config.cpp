class CfgPatches
{
    class ld3k_jca_mp5a5_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_IA_SMGs_MP5",
            "Weapons_F_JCA_MP5",
            "Weapons_F_JCA_MP5_Accessories"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    // JCA Bullets inherited from vanilla class B_9x21_Ball. To avoid all conflict with other mod, all JCA bullets with JCA as prefixe.
    // class B_9x21_Ball: BulletBase from official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class BulletBase;
    /*class B_9x21_Ball: BulletBase
    {
        hit=5;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=380;
        airFriction=-0.0016;
        caliber=1.2;
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=1;
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class B_9x21_Ball_Tracer_Green: B_9x21_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0;
    };
    class B_9x21_Ball_Tracer_Red: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class B_9x21_Ball_Tracer_Yellow: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x21_Ball_Tracer_IR: B_9x21_Ball_Tracer_Green // JCA default config
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        nvgOnly=1;
    };
    class ACE_9x19_Ball: B_9x21_Ball // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L505
    {
        airFriction=-0.00201185;
        ACE_caliber=9.017;
        ACE_bulletLength=15.494;
        ACE_bulletMass=8.0352;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619};
        ACE_ballisticCoefficients[]={0.165};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={340,370,400};
        ACE_barrelLengths[]={101.6,127.0,228.6};
    };*/
    class JCA_B_9x19_Ball_MP5_FMJ: BulletBase // M17 Sig Sauer NATO 9x19mm +P 124gr FMJ https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" https://www.sigsauer.com/9mm-p-124gr-elite-ball-m17-fmj-box-50.html
        ACE_bulletMass=8.035; // 124gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.235}; // recalculated ICAO G1 BC based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127.0,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={366,398,430}; // at 21°C (70°F: Temp vs MV chart zero), 365m/s (1198fps) 4" barrel - 428m/s (1404fps) 8.858" (225mm) barrel at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_MP5A5 initSpeed
        hit=5.4; // B_9x21_Ball 5, 736 Joules
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=428; // JCA_30Rnd_9x19_MP5_FMJ_Mag and JCA_30Rnd_9x19_MP5_JHP_Mag initSpeed
        airFriction=-0.0015693; // ACE3 -0.00201185, B_9x21_Ball -0.0016, airFrictionAnalysis.txt in docs folder
        caliber=1.2;
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0; // B_9x21_Ball 1
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class JCA_B_9x19_Ball_MP5_JHP: JCA_B_9x19_Ball_MP5_FMJ // M17 Sig Sauer NATO 9x19mm +P 124gr V-Crown https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" https://www.sigsauer.com/9mm-p-124gr-elite-ball-m17-fmj-box-50.html
        ACE_bulletMass=8.035; // 124gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.204}; // recalculated ICAO G1 BC based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127.0,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={366,398,430}; // at 21°C (70°F: Temp vs MV chart zero), 365m/s (1198fps) 4" barrel - 428m/s (1404fps) 8.858" (225mm) barrel at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_MP5A5 initSpeed
        hit=9; // B_9x21_Ball 5, 736 Joules
        airFriction=-0.00180949; // airFrictionAnalysis.txt in docs folder
        caliber=0.72; // B_9x21_Ball 1.2
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Green: JCA_B_9x19_Ball_MP5_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Red: JCA_B_9x19_Ball_MP5_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Yellow: JCA_B_9x19_Ball_MP5_FMJ
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_IR: JCA_B_9x19_Ball_MP5_FMJ
    {
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    // class 16Rnd_9x21_Mag: 30Rnd_9x21_Mag from official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    /*class 30Rnd_9x21_Mag: CA_Magazine
    {
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_9x21_Mag0";
        picture="\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
        ammo="B_9x21_Ball";
        count=30;
        mass=10;
        initSpeed=370;
        tracersEvery=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_9x21_Mag1";
    };
    class 16Rnd_9x21_Mag: 30Rnd_9x21_Mag
    {
        author="$STR_A3_Bohemia_Interactive";
        displayName="$STR_A3_CfgMagazines_16Rnd_9x21_Mag0";
        picture="\A3\weapons_f\data\ui\M_16Rnd_9x21_CA.paa";
        type=16;
        count=16;
        descriptionShort="$STR_A3_CfgMagazines_16Rnd_9x21_Mag1";
        mass=6;
        initSpeed=410;
    };*/
    class JCA_30Rnd_9x19_MP5_FMJ_Mag: CA_Magazine // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        scope=2;
        displayName="9 mm 30Rnd MP5 FMJ Mag";
        picture="\weapons_f_JCA_MP5\MagazineProxies\data\UI\Icon_30Rnd_MP5_MAG_CA.paa";
        modelSpecial="weapons_f_JCA_MP5\MagazineProxies\30Rnd_MP5_MAG.p3d";
        modelSpecialIsProxy=1;
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_MP5\SMGs\MP5\Data\smg_MP5_02_black_CO.paa"
        };
        ammo="JCA_B_9x19_Ball_MP5_FMJ";
        count=30;
        mass=11.9; // magazine 30 rounds empty 170g + 30x 12.3g, JCA 10
        initSpeed=428; // according to ACE_muzzleVelocities 8.858" barrel (225mm) ICAO conditions (15°C, 1013.25hPa, 0%), JCA 370
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="Caliber: 9x19 mm<br />Rounds: 30<br />Used in: MP5A5";
        displaynameshort="FMJ";
    };
    class JCA_30Rnd_9x19_MP5_JHP_Mag: JCA_30Rnd_9x19_MP5_FMJ_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Jacketed Hollow Point JHP
    {
        author="Grave";
        displayName="9 mm 30Rnd MP5 JHP Mag";
        ammo="JCA_B_9x19_Ball_MP5_JHP";
        displaynameshort="JHP";
    };
    class JCA_30Rnd_9x19_MP5_Red_Mag: JCA_30Rnd_9x19_MP5_FMJ_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Red) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_9x19_MP5_Green_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Green) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Yellow_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Yellow) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_IR_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (IR) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_IR";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Red_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Red) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Green_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Green) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Yellow) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_IR_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (IR) MP5 Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag: JCA_30Rnd_9x19_MP5_FMJ_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd MP5 FMJ Sand Mag";
        picture="\weapons_f_JCA_MP5\MagazineProxies\data\UI\Icon_30Rnd_MP5_MAG_sand_CA.paa";
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_MP5\SMGs\MP5\Data\smg_MP5_02_sand_CO.paa"
        };
        displaynameshort="FMJ";
    };
    class JCA_30Rnd_9x19_MP5_JHP_Sand_Mag: JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Jacketed Hollow Point JHP
    {
        author="Grave";
        displayName="9 mm 30Rnd MP5 JHP Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_JHP";
        displaynameshort="JHP";
    };
    class JCA_30Rnd_9x19_MP5_Red_Sand_Mag: JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Red) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_9x19_MP5_Green_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Green) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (Yellow) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_IR_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Reload Tracer (IR) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_IR";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Red) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Green) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (Yellow) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        author="Grave";
        displayName="9 mm 30Rnd Tracer (IR) MP5 Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    /*class JCA_MP5_9x21 // JCA default config
    {
        JCA_Magazines[]=
        {
            "JCA_30Rnd_9x21_MP5_Mag",
            "JCA_30Rnd_9x21_MP5_Red_Mag",
            "JCA_30Rnd_9x21_MP5_Green_Mag",
            "JCA_30Rnd_9x21_MP5_Yellow_Mag",
            "JCA_30Rnd_9x21_MP5_IR_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_IR_Mag",
            "JCA_30Rnd_9x21_MP5_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x21_MP5_Tracer_IR_Sand_Mag"
        };
    };*/
    class JCA_MP5_9x19 // Weapon initSpeed -1 with ACE_barrelLength 225mm, 428m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_9x19_MP5_FMJ_Mag and JCA_30Rnd_9x19_MP5_JHP_Mag initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_FMJ_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag",
            "JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag"
        };
    };
};
class Mode_FullAuto;
class Mode_SemiAuto;
class CfgWeapons
{
    class ItemCore;
    class InventoryMuzzleItem_Base_F;
    class Rifle_Base_F;
    class Rifle_Short_Base_F: Rifle_Base_F
    {
        class WeaponSlotsInfo;
    };
    class JCA_smg_MP5_base_F: Rifle_Short_Base_F // https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Submachine%20guns/MP5?section=variants&s=true
    {
        ACE_barrelLength=225; // 8.858"
        ACE_barrelTwist=250; // CIP twist https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_RailHeightAboveBore=3.74837;  // from ACE3 checkScopes.sqf
        initSpeed=-1; // 428m/s, 225mm barrel, according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 375
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_9x19_MP5_FMJ_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag",
            "JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag"
        };
        magazineWell[]=
        {
            "JCA_MP5_9x19"
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000765; // 4.68 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00116 (3.99 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.000765; // 4.68 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00116 (3.99 MOA)
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=67.9; // 3080g w/o magazine https://de.wikipedia.org/wiki/HK_MP5, JCA 70
        };
    };
    class JCA_smg_MP5_AFG_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_VFG_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_FL_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_AFG_sand_F: JCA_smg_MP5_AFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_FMJ_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_smg_MP5_VFG_sand_F: JCA_smg_MP5_VFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_FMJ_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_smg_MP5_FL_sand_F: JCA_smg_MP5_FL_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_9x19_MP5_FMJ_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_FMJ_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_muzzle_snds_MP5_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_MP5_black: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_MP5_sand: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_MP5_olive: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // muzzle_snds_L 1
                recoilProneCoef=0.95; // muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
};