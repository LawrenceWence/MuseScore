/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2022 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MU_APPSHELL_LOADINGSCREENVIEW_H
#define MU_APPSHELL_LOADINGSCREENVIEW_H

#include <QWidget>

#include "modularity/ioc.h"
#include "ui/iuiconfiguration.h"
#include "languages/ilanguagesservice.h"
#include "global/iapplication.h"

class QSvgRenderer;

namespace mu::appshell {
class LoadingScreenView : public QWidget
{
    Q_OBJECT

    Inject<ui::IUiConfiguration> uiConfiguration;
    Inject<languages::ILanguagesService> languagesService;
    Inject<IApplication> application;

public:
    explicit LoadingScreenView(QWidget* parent = nullptr);

private:
    bool event(QEvent* event) override;
    void draw(QPainter* painter);

    QString m_message;
    QSvgRenderer* m_backgroundRenderer = nullptr;
};
}

#endif // MU_APPSHELL_LOADINGSCREENVIEW_H
