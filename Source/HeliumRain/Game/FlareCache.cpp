
#include "FlareCache.h"
#include "../Flare.h"
#include "FlareGame.h"

#define LOCTEXT_NAMESPACE "FlareCacheSystem"
#define DEBUG_SPACECRAFT_CACHE

/*----------------------------------------------------
	Constructor
----------------------------------------------------*/

//TODO: perhaps use TMap or multi-layered Array and more generic get/store for each type
//Key would probably be a string

UFlareCacheSystem::UFlareCacheSystem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFlareCacheSystem::InitialSetup(AFlareGame* GameMode)
{
	FCHECK(GameMode);
	Game = GameMode;

	CachedShells.Empty();
	CachedBombs.Empty();
	CachedAsteroids.Empty();
	CachedDebris.Empty();
	CachedSpacecraft.Empty();

	// Ships
	ID_ShipSolen = "ship-solen";
	ID_ShipOmen = "ship-omen";
	ID_ShipGhoul = "ship-ghoul";
	ID_ShipOrca = "ship-orca";
	ID_ShipPhalanx = "ship-phalanx";

	ID_ShipSphinx = "ship-sphinx";
	ID_ShipThemis = "ship-themis";
	ID_ShipAtlas = "ship-atlas";

	ID_ShipDragon = "ship-dragon";
	ID_ShipKami = "ship-kami";
	ID_ShipInvader = "ship-invader";
	ID_ShipLeviathan = "ship-leviathan";
	ID_ShipAnubis = "ship-anubis";

	// Stations
	ID_StationComplex = "station-complex";

	ID_StationFarm = "station-farm";
	ID_StationFarm_Sub_TF = "station-tf-farm";

	ID_StationSolarPlant = "station-solar-plant";
	ID_StationSolarPlant_Sub_TF = "station-tf-solar-plant";

	ID_StationHabitation = "station-habitation";
	ID_StationHabitation_Sub_BH = "station-bh-habitation";
	ID_StationHabitation_Sub_BY = "station-by-habitation";
	ID_StationHabitation_Sub_NH = "station-nh-habitation";
	ID_StationHabitation_Sub_TF = "station-tf-habitation";

	ID_StationIceMine = "station-ice-mine";
	ID_StationIronMine = "station-iron-mine";
	ID_StationSilicaMine = "station-silica-mine";
	ID_StationSteelworks = "station-steelworks";
	ID_StationToolFactory = "station-tool-factory";
	ID_StationHydrogenPump = "station-h2-pump";
	ID_StationMethanePump = "station-ch4-pump";
	ID_StationHeliumPump = "station-he3-pump";
	ID_StationCarbonRefinery = "station-carbon-refinery";
	ID_StationPlasticsRefinery = "station-plastics-refinery";

	ID_StationArsenal = "station-arsenal";
	ID_StationArsenal_Sub_BH = "station-bh-arsenal";
	ID_StationArsenal_Sub_BY = "station-by-arsenal";
	ID_StationArsenal_Sub_NH = "station-nh-arsenal";
	ID_StationArsenal_Sub_TF = "station-tf-arsenal";

	ID_StationShipyard = "station-shipyard";
	ID_StationShipyard_Sub_BH = "station-bh-shipyard";
	ID_StationShipyard_Sub_BY = "station-by-shipyard";
	ID_StationShipyard_Sub_NH = "station-nh-shipyard";

	ID_StationHub = "station-hub";
	ID_StationHub_Sub_BH = "station-bh-hub";
	ID_StationHub_Sub_BY = "station-by-hub";
	ID_StationHub_Sub_TF = "station-tf-hub";

	ID_StationOutpost = "station-outpost";
	ID_StationFoundry = "station-foundry";
	ID_StationFusion = "station-tokamak";

	ID_StationResearch = "station-research";
	ID_StationTelescope = "station-telescope";

	//Technologies

	ID_TechAutoDocking =	  "auto-docking";
	ID_TechScience =		  "science";
	ID_TechLogistics =		  "stations";
	ID_TechEarlyWarning =	  "early-warning";
	ID_TechInstruments =	  "instruments";
	ID_TechMetallurgy =		  "metallurgy";
	ID_TechChemicals =		  "chemicals";
	ID_TechMining =			  "mining";
	ID_TechQuickRepairs =	  "quick-repair";
	ID_TechOrbitalPumps =     "orbital-pumps";
	ID_TechAdvancedRadar =    "advanced-radar";
	ID_TechFlak =			  "flak";
	ID_TechDiplomacy =		  "diplomacy";
	ID_TechShipyard =		  "shipyard-station";
	ID_TechPirateTech =		  "pirate-tech";
	ID_TechBombing =		  "bombing";
	ID_TechDenseSectors =	  "dense-sectors";
	ID_TechFastTravel =		  "fast-travel";
	ID_TechAutomatedTrading = "auto-trade";
	ID_TechAdvancedStations = "advanced-stations";
	ID_TechNegociations =	  "negociations";

	ID_WeaponSalvageLight =	  "weapon-light-salvage";
	ID_WeaponSalvageHeavy =   "weapon-heavy-salvage";

	ID_WeaponHades =		  "weapon-hades";
	ID_WeaponMjolnir =		  "weapon-mjolnir";

	ID_WeaponWyrm =			  "weapon-wyrm";
	ID_WeaponSparrow =		  "weapon-sparrow";
	ID_WeaponHydra =		  "weapon-hydra";

	ID_WeaponEradicator =	  "weapon-eradicator";
	ID_WeaponHammer =		  "weapon-hammer";
	ID_WeaponAres =			  "weapon-ares";
	ID_WeaponArtemis =		  "weapon-artemis";
}


void UFlareCacheSystem::StoreCachedSpacecraft(AFlareSpacecraft* Spacecraft)
{
	if (CachedSpacecraft.Contains(Spacecraft->GetParent()->GetDescription()->SpacecraftTemplate))
	{
		CachedSpacecraft[Spacecraft->GetParent()->GetDescription()->SpacecraftTemplate].TrackedSpacecraft.Add(Spacecraft);

#ifdef DEBUG_SPACECRAFT_CACHE
		FLOGV("UFlareCacheSystem::StoreCachedSpacecraft Store '%s' (template '%s') as already existing cache entry",
			*Spacecraft->GetParent()->GetImmatriculation().ToString(),
			*Spacecraft->GetParent()->GetDescription()->SpacecraftTemplate->GetName())
#endif

	}
	else
	{
		FFlareSpacecraftCacheHelper NewCacheHelper;
		NewCacheHelper.TrackedSpacecraft.Add(Spacecraft);
		CachedSpacecraft.Add(Spacecraft->GetParent()->GetDescription()->SpacecraftTemplate, NewCacheHelper);

#ifdef DEBUG_SPACECRAFT_CACHE
		FLOGV("UFlareCacheSystem::StoreCachedSpacecraft Store '%s' (template '%s') as NewCacheHelper",
			*Spacecraft->GetParent()->GetImmatriculation().ToString(),
			*Spacecraft->GetParent()->GetDescription()->SpacecraftTemplate->GetName())
#endif

	}
}

AFlareSpacecraft* UFlareCacheSystem::RetrieveCachedSpacecraft(UClass* SpacecraftType)
{
	if (CachedSpacecraft.Contains(SpacecraftType) && CachedSpacecraft[SpacecraftType].TrackedSpacecraft.Num() > 0)
	{

#ifdef DEBUG_SPACECRAFT_CACHE
		FLOGV("UFlareCacheSystem::RetrieveCachedSpacecraft Retrieve '%s' for 'new' ship",
			*SpacecraftType->GetName())
#endif

			return CachedSpacecraft[SpacecraftType].TrackedSpacecraft.Pop();
	}
	return nullptr;
}

void UFlareCacheSystem::StoreCachedShell(AFlareShell* Shell)
{
	if (Shell)
	{
		CachedShells.Add(Shell);
	}
}

AFlareShell* UFlareCacheSystem::RetrieveCachedShell()
{
	if (CachedShells.Num() > 0)
	{
		AFlareShell* Shell = CachedShells.Pop();
		return Shell;
	}
	return NULL;
}

void UFlareCacheSystem::StoreCachedBomb(AFlareBomb* Bomb)
{
	if (Bomb)
	{
		CachedBombs.Add(Bomb);
	}
}

AFlareBomb* UFlareCacheSystem::RetrieveCachedBomb()
{
	if (CachedBombs.Num() > 0)
	{
		AFlareBomb* Bomb = CachedBombs.Pop();
		return Bomb;
	}
	return NULL;
}

void UFlareCacheSystem::StoreCachedAsteroid(AFlareAsteroid* Asteroid)
{
	if (Asteroid)
	{
		CachedAsteroids.Add(Asteroid);
	}
}

AFlareAsteroid* UFlareCacheSystem::RetrieveCachedAsteroid()
{
	if (CachedAsteroids.Num() > 0)
	{
		AFlareAsteroid* Asteroid = CachedAsteroids.Pop();
		return Asteroid;
	}
	return NULL;
}

void UFlareCacheSystem::StoreCachedMeteorite(AFlareMeteorite* Meteorite)
{
	if (Meteorite)
	{
		CachedMeteorites.Add(Meteorite);
	}
}

AFlareMeteorite* UFlareCacheSystem::RetrieveCachedMeteorite()
{
	if (CachedMeteorites.Num() > 0)
	{
		AFlareMeteorite* Meteorite = CachedMeteorites.Pop();
		return Meteorite;
	}
	return NULL;
}

void UFlareCacheSystem::StoreCachedDebris(AStaticMeshActor* Debris)
{
	if (Debris)
	{
		CachedDebris.Add(Debris);
	}
}

AStaticMeshActor* UFlareCacheSystem::RetrieveCachedDebris()
{
	if (CachedDebris.Num() > 0)
	{
		AStaticMeshActor* Debris = CachedDebris.Pop();
		return Debris;
	}
	return NULL;
}

void UFlareCacheSystem::StoreCachedTravel(UFlareTravel* Travel)
{
	if (Travel)
	{
		CachedTravels.Add(Travel);
	}
}

UFlareTravel* UFlareCacheSystem::RetrieveCachedTravel()
{
	if (CachedTravels.Num() > 0)
	{
		UFlareTravel* Travel = CachedTravels.Pop();
		return Travel;
	}
	return NULL;
}

#undef LOCTEXT_NAMESPACE