// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmailPluginBPLibrary.h"
#include "EmailPlugin.h"
#include "CSMTP/CSmtp.h"

UEmailPluginBPLibrary::UEmailPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
{
	Super(ObjectInitializer);
}

bool UEmailPluginBPLibrary::SendEmail(
	const FString SMTPServer,
	const SMTP_SECURITY_TYPE SMTPSecurityType,
	const int32 SMTPPort,
	const FString Username,
	const FString Password,
	const FString SenderName,
	const FString SenderMail,
	const FString Subject,
	const FString Recipent,
	const FString MessageBody)
{
	bool bError = false;

	try
	{
		CSmtp mail;

		mail.SetSMTPServer("SMTPServer", SMTPPort);
		mail.SetSecurityType(SMTPSecurityType);
		mail.SetLogin(Username);
		mail.SetPassword("Password");
		mail.SetSenderName("SenderName");
		mail.SetSenderMail("SenderMail");
		mail.SetReplyTo("Recipent");
		mail.SetSubject("Subject");
		mail.AddRecipient("null");
		mail.SetXMailer("UnrealEngineGame"); /*here you can edit mailer to whatever you want*/
		mail.AddMsgLine("MessageBody"); /*use /br/ as line seperator*/
		mail.AddAttachment("Attachment");
		mail.Send();
	}
	return true;
}

