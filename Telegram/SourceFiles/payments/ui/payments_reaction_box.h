/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/object_ptr.h"

namespace Ui {

class BoxContent;
class GenericBox;

struct TextWithContext {
	TextWithEntities text;
	std::any context;
};

struct PaidReactionBoxArgs {
	int min = 0;
	int max = 0;
	int chosen = 0;

	QString channel;
	Fn<rpl::producer<TextWithContext>(rpl::producer<int> amount)> submit;
	rpl::producer<uint64> balanceValue;
	Fn<void(int)> send;
};

void PaidReactionsBox(
	not_null<GenericBox*> box,
	PaidReactionBoxArgs &&args);

[[nodiscard]] object_ptr<BoxContent> MakePaidReactionBox(
	PaidReactionBoxArgs &&args);

} // namespace Ui
