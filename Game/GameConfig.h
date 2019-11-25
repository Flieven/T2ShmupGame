#pragma once

#include <SDL.h>

/*
USE THIS .h FILE TO CREATE STATIC VARIABLES USED IN OTHER AREAS OF CODE.
ESSENTIALLY ALL FILEPATHS IN ASSETS, WINDOW SIZES, PLAYER SIZE, ETC.
*/



// ===== WINDOW SETTINGS =====
static const char* windowTitle = "ShmupGame";
static int windowWidth = 600;
static int windowHeight = 900;

static SDL_Color backgroundColor = { 30, 30, 60, 255 };
// ===========================

// ===== BACKGROUND SETTINGS =====
static int backgroundWidth = 600;
static int backgroundHeight = 900;
static const int backgroundTag = 0;
static const char* backgroundSprite = "../Assets/Sprites/BgTest.png";
// ===========================

// ===== CLOUD TEST =====
static int cloudWidth = 600;
static int cloudHeight = 900;
static const int cloudTag = 1;
static const char* cloudSprite = "../Assets/Sprites/Cloud.png";
// ===========================

// ===== BULLET SEINGS =====
static int bulletWidth = 25;
static int bulletHeight = 15;
static const int bulletTag = 2;
static const char* bulletSprite = "../Assets/Sprites/YodaSmall.png";
// ===========================

// ===== PLAYER SETTINGS =====
static int playerWidth = 25;
static int playerHeight = 60;
//static std::string playerTag = "Player";
static const int playerTag = 3;
static const char* playerSprite = "../Assets/Sprites/SDL_Player.png";
// ===========================

// ===== ENEMY SETTINGS =====
static int enemyWidth = 87;
static int enemyHeight = 23;
//static std::string enemyTag = "Enemy";
static const int enemyTag = 4;
static const char* enemySprite = "../Assets/Sprites/CampFire.png";
// ===========================



// ===== UPGRADE SETTINGS =====
// ============================

// ===== DEBUG SETTINGS =====
static SDL_Color debugColor = { 0, 255, 0, 255 };
// =========================

// ===== MISC SETTINGS =====
// =========================