#pragma once

#include "Geometry.h"
#include "SceneEnum.h"
#include "Bounds3.h"

namespace PhysX
{
	ref class SweepHit;
	ref class RaycastHit;

	public ref class GeometryQuery
	{
	public:
		static SweepHit^ Sweep(Vector3 unitDirection, float distance, Geometry^ geom0, Matrix pose0, Geometry^ geom1, Matrix pose1, [Optional] Nullable<HitFlag> hitFlags, [Optional] Nullable<float> inflation);

		// TODO: Overlap
		// TODO: ComputePenetration
		// TODO: PointDistance

		static Bounds3 GetWorldBounds(Geometry^ geometry, Matrix pose, [Optional] Nullable<float> inflation);

		static array<RaycastHit^>^ Raycast(Vector3 origin, Vector3 unitDirection, Geometry^ geom0, Matrix pose0, float distance, int maxHits, [Optional] Nullable<HitFlag> hitFlags);
	};
}