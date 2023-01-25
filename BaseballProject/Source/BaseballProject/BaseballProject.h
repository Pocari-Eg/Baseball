// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(Baseball_LOG, Log, All);
#define BBLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define BBLOG_S(Verbosity) UE_LOG(Lucia, Verbosity, TEXT("%s"), *BBLOG_CALLINFO)
#define BBLOG(Verbosity, Format, ...) UE_LOG(Baseball_LOG, Verbosity, TEXT("%s %s"), *BBLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define BBCHECK(Expr, ...) {if(!(Expr)) {BBLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__;}}
