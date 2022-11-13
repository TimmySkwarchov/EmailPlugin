// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "EmailPluginBPLibrary.generated.h"

/*
* Here you can modify source code for yours. 
* My philosophy
* I wanted to make these plugins paid,
* but people will waste their money,
* more and more paid assets appearing
* in the UE Marketplace. So I did the economy.
* Have a great day and have a nice weather!
*/
UCLASS()
class UEmailPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
		/*
		* Sends email in one node. Useful when
		* it needs for bug reports or verification mail.
		* If you are doing verification mail, make sure you have
		* server that stores data (Gamejolt for example) and OTP
		* for verifying.
		* @param SMTPServer Target where email sended. Example: smtp.gmail.com
		* @param SecurityType USE_SSL is for using OpenSSL. USE_TLS is for TLS connection
		* @param SMTPPort Refer to documantation for more information
		* @param Username Many SMTP servers are requiring user auth to prevent spamming. If not, email will not being sent
		* @param Password
		* @param SenderName Name of the sender displayed instead of email
		* @param SenderMail Post mail like from you for example
		* @param Subject Header displayed on email
		* @param Recipent Send email to target mail account.
		* @param MessageBody Use /br/ as line seperator
		*/

		UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send Email via CSMTP", Keywords = ("EmailPlugin - Blueprints"), Category = "Email Plugin - Blueprints")
			UEmailPluginBPLibrary(const FObjectInitializer & ObjectInitializer);
	static bool SendEmail(
		const FString SMTPServer,
		const SMTP_SECURITY_TYPE SMTPSecurityType,
		const int32 SMTPPort,
		const FString Username,
		const FString Password,
		const FString SenderName,
		const FString SenderMail,
		const FString Subject,
		const FString Recipent,
		const FString MessageBody);
}
