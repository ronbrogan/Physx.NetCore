#pragma once

namespace PhysX
{
	/// <summary>
	/// An array of contact points, as passed to contact modification.
	/// </summary>
	public ref class ContactSet
	{
	private:
		PxContactSet* _contactSet;

	internal:
		ContactSet(PxContactSet unmanaged);
	protected:
		~ContactSet();
	public:
		!ContactSet();

		Vector3 GetPoint(int i);
		void SetPoint(int i, Vector3 p);

		Vector3 GetNormal(int i);
		void SetNormal(int i, Vector3 n);

		float GetSeparation(int i);
		void SetSeparation(int i, float s);

		float GetDynamicFriction(int i);
		void SetDynamicFriction(int i, float f);
		float GetStaticFriction(int i);
		void SetStaticFriction(int i, float f);
		float GetRestitution(int i);
		void SetRestitution(int i, float f);

		Vector3 GetTargetVelocity(int i);
		void SetTargetVelocity(int i, Vector3 v);

		int GetInternalFaceIndex0(int i);
		int GetInternalFaceIndex1(int i);

		float GetMaxImpulse(int i);
		void SetMaxImpulse(int i, float s);

		void Ignore(int i);
		property int Size
		{
			int get();
		}

		float GetInvMassScale0();
		float GetInvMassScale1();

		float GetInvInertiaScale0();
		float GetInvInertiaScale1();

		void SetInvMassScale0(float scale);
		void SetInvMassScale1(float scale);

		void SetInvInertiaScale0(float scale);
		void SetInvInertiaScale1(float scale);

	internal:
		property PxContactSet* UnmanagedPointer
		{
			PxContactSet* get();
		}
	};
}