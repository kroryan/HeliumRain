#pragma once

#include "Object.h"
#include "FlareCache.generated.h"

class AFlareGame;
class UFlareSimulatedSector;
class AFlareShell;
class AFlareBomb;
class AFlareAsteroid;
class AFlareMeteorite;

USTRUCT()
struct FFlareSpacecraftCacheHelper
{
	GENERATED_USTRUCT_BODY()

	TArray<AFlareSpacecraft*> TrackedSpacecraft;
};

UCLASS()
class HELIUMRAIN_API UFlareCacheSystem : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	/*----------------------------------------------------
		Public interface
	----------------------------------------------------*/
	void InitialSetup(AFlareGame* GameMode);

	void StoreCachedSpacecraft(AFlareSpacecraft* Spacecraft);
	AFlareSpacecraft* RetrieveCachedSpacecraft(UClass* SpacecraftType);

	void StoreCachedShell(AFlareShell* Shell);
	AFlareShell* RetrieveCachedShell();

	void StoreCachedBomb(AFlareBomb* Bomb);
	AFlareBomb* RetrieveCachedBomb();

	void StoreCachedAsteroid(AFlareAsteroid* Asteroid);
	AFlareAsteroid* RetrieveCachedAsteroid();

	void StoreCachedMeteorite(AFlareMeteorite* Meteorite);
	AFlareMeteorite* RetrieveCachedMeteorite();

	void StoreCachedDebris(AStaticMeshActor* Debris);
	AStaticMeshActor* RetrieveCachedDebris();

	void StoreCachedTravel(UFlareTravel* Travel);
	UFlareTravel* RetrieveCachedTravel();

	// Ships
	FName                                      ID_ShipSolen;
	FName                                      ID_ShipOmen;
	FName                                      ID_ShipGhoul;
	FName                                      ID_ShipOrca;
	FName                                      ID_ShipPhalanx;

	FName                                      ID_ShipSphinx;
	FName                                      ID_ShipThemis;
	FName                                      ID_ShipAtlas;
	FName                                      ID_ShipDragon;
	FName                                      ID_ShipKami;
	FName                                      ID_ShipInvader;
	FName                                      ID_ShipLeviathan;
	FName                                      ID_ShipAnubis;

	// Stations
	FName		 							   ID_StationComplex;

	FName                                      ID_StationFarm;
	FName                                      ID_StationFarm_Sub_TF;

	FName                                      ID_StationSolarPlant;
	FName                                      ID_StationSolarPlant_Sub_TF;

	FName                                      ID_StationHabitation;
	FName                                      ID_StationHabitation_Sub_BH;
	FName                                      ID_StationHabitation_Sub_BY;
	FName                                      ID_StationHabitation_Sub_NH;
	FName                                      ID_StationHabitation_Sub_TF;

	FName                                      ID_StationIceMine;
	FName                                      ID_StationIronMine;
	FName                                      ID_StationSilicaMine;
	FName                                      ID_StationSteelworks;
	FName                                      ID_StationToolFactory;
	FName                                      ID_StationHydrogenPump;
	FName                                      ID_StationHeliumPump;
	FName                                      ID_StationMethanePump;
	FName                                      ID_StationCarbonRefinery;
	FName                                      ID_StationPlasticsRefinery;

	FName                                      ID_StationArsenal;
	FName                                      ID_StationArsenal_Sub_BH;
	FName                                      ID_StationArsenal_Sub_BY;
	FName                                      ID_StationArsenal_Sub_NH;
	FName                                      ID_StationArsenal_Sub_TF;

	FName                                      ID_StationShipyard;
	FName                                      ID_StationShipyard_Sub_BH;
	FName                                      ID_StationShipyard_Sub_BY;
	FName                                      ID_StationShipyard_Sub_NH;

	FName                                      ID_StationHub;
	FName                                      ID_StationHub_Sub_BH;
	FName                                      ID_StationHub_Sub_BY;
	FName                                      ID_StationHub_Sub_TF;

	FName                                      ID_StationOutpost;
	FName									   ID_StationFoundry;
	FName									   ID_StationFusion;
	FName									   ID_StationResearch;
	FName									   ID_StationTelescope;

	// Technology IDS
	FName									   ID_TechAutoDocking;
	FName									   ID_TechScience;
	FName									   ID_TechLogistics; // (Stations)
	FName									   ID_TechEarlyWarning;
	FName									   ID_TechInstruments;
	FName									   ID_TechMetallurgy;
	FName									   ID_TechChemicals;
	FName									   ID_TechMining;
	FName									   ID_TechQuickRepairs;
	FName									   ID_TechOrbitalPumps;
	FName									   ID_TechAdvancedRadar;
	FName									   ID_TechFlak;
	FName									   ID_TechDiplomacy;
	FName									   ID_TechShipyard;
	FName									   ID_TechPirateTech;
	FName									   ID_TechBombing;
	FName									   ID_TechDenseSectors;
	FName									   ID_TechFastTravel;
	FName									   ID_TechAutomatedTrading;
	FName									   ID_TechAdvancedStations;
	FName									   ID_TechNegociations;

	// Weapon IDS
	FName									   ID_WeaponSalvageLight;
	FName									   ID_WeaponSalvageHeavy;

	FName									   ID_WeaponHades;
	FName									   ID_WeaponMjolnir;

	FName									   ID_WeaponWyrm;
	FName									   ID_WeaponSparrow;
	FName									   ID_WeaponHydra;

	FName									   ID_WeaponEradicator;
	FName									   ID_WeaponHammer;
	FName									   ID_WeaponAres;
	FName									   ID_WeaponArtemis;

private:

	/*----------------------------------------------------
		Internals
	----------------------------------------------------*/

protected:

	/*----------------------------------------------------
		Protected data
	----------------------------------------------------*/

	/** Game reference */
	UPROPERTY()
	AFlareGame*                                Game;

	UPROPERTY()
	TArray<AFlareShell*>					   CachedShells;

	UPROPERTY()
	TArray<AFlareBomb*>						   CachedBombs;

	UPROPERTY()
	TArray<AFlareAsteroid*>					   CachedAsteroids;

	UPROPERTY()
	TArray<AFlareMeteorite*>				   CachedMeteorites;

	UPROPERTY()
	TArray<AStaticMeshActor*>				   CachedDebris;

	UPROPERTY()
	TArray<UFlareTravel*>					   CachedTravels;

	UPROPERTY()
	TMap<UClass*, FFlareSpacecraftCacheHelper> CachedSpacecraft;
};