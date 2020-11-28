#pragma once

#include "PvdEnum.h"

using namespace PhysX::VisualDebugger;

namespace PhysX
{
	ref class Scene;

	public ref class PvdSceneClient : IDisposable
	{
	public:
		virtual event EventHandler^ OnDisposing;
		virtual event EventHandler^ OnDisposed;


	private:
		PxPvdSceneClient* _pvdSceneClient;

	public:
		PvdSceneClient(Scene^ scene);
		~PvdSceneClient();
	protected:
		!PvdSceneClient();

	public:
		property bool Disposed
		{
			virtual bool get();
		}
		void SetScenePvdFlags(SceneVisualizationFlags flags);

	internal:
		property PxPvdSceneClient* UnmanagedPointer
		{
			PxPvdSceneClient* get();
		}
	};
};