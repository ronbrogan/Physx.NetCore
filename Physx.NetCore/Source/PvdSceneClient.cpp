#include "StdAfx.h"
#include "PvdSceneClient.h"
#include "Physics.h"
#include "Scene.h"

using namespace PhysX;
using namespace PhysX::VisualDebugger;

PvdSceneClient::PvdSceneClient(Scene^ scene)
{
	ThrowIfNullOrDisposed(scene, "scene");

	_pvdSceneClient = scene->UnmanagedPointer->getScenePvdClient();

	ObjectTable::Instance->Add((intptr_t)_pvdSceneClient, this, scene);
}

void PvdSceneClient::SetScenePvdFlags(SceneVisualizationFlags flags)
{
	_pvdSceneClient->setScenePvdFlags(ToUnmanagedEnum(PxPvdSceneFlag, flags));
}

PvdSceneClient::~PvdSceneClient()
{
	this->!PvdSceneClient();
}
PvdSceneClient::!PvdSceneClient()
{
	OnDisposing(this, nullptr);

	if (Disposed)
		return;

	_pvdSceneClient = NULL;

	OnDisposed(this, nullptr);
}

bool PvdSceneClient::Disposed::get()
{
	return (_pvdSceneClient == NULL);
}

PxPvdSceneClient* PvdSceneClient::UnmanagedPointer::get()
{
	return _pvdSceneClient;
}