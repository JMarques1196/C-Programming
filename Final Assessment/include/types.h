/**
 * types.h - Type definitions and constants for the GreenTrack system.
 *
 * Defines the data structures and maximum limits used
 * by the plants, waterings, and tasks modules.
 */

#ifndef TYPES_H
#define TYPES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ── System limits ─────────────────────────────────────────── */
#define MAX_PLANTS 100
#define MAX_WATERINGS 500
#define MAX_TASKS 200

/* ── Data types ────────────────────────────────────────────── */

typedef struct
{
    int id;
    char name[50];
    char species[50];
    char planting_date[11]; /* DD/MM/YYYY */
    int watering_interval;  /* in days */
    int last_watering;      /* timestamp: days since 01/01/2026 */
} Plant;

typedef struct
{
    int watering_id;
    int plant_id;
    int watering_date;  /* timestamp: days since 01/01/2026 */
    int water_quantity; /* in ml */
} Watering;

typedef struct
{
    int task_id;
    char description[100];
    int due_date;  /* timestamp: days since 01/01/2026 */
    int completed; /* 0 = pending | 1 = completed */
} Task;

#endif