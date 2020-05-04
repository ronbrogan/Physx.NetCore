#include "StdAfx.h"
#include "LocationHit.h"

void LocationHit::PopulateUnmanaged(PxLocationHit& hit)
{
	QueryHit::PopulateUnmanaged(hit);

	hit.flags = ToUnmanagedEnum(PxHitFlag, this->Flags);
	hit.position = MathUtil::Vector3ToPxVec3(this->Position);
	hit.normal = MathUtil::Vector3ToPxVec3(this->Normal);
	hit.distance = this->Distance;
}
void LocationHit::PopulateManaged(PxLocationHit hit)
{
	QueryHit::PopulateManaged(hit);

	this->Flags = ToManagedEnum(HitFlag, hit.flags);
	this->Position = MathUtil::PxVec3ToVector3(hit.position);
	this->Normal = MathUtil::PxVec3ToVector3(hit.normal);
	this->Distance = hit.distance;
}