/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 RC 1        *
*                (c) 2006-2011 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <sofa/component/collision/RayContact.h>
#include <sofa/core/visual/VisualParams.h>
#include <sofa/component/collision/RayModel.h>
#include <sofa/component/collision/SphereModel.h>
#include <sofa/component/collision/TriangleModel.h>
#include <sofa/component/collision/OBBModel.h>

namespace sofa
{

namespace component
{

namespace collision
{

using namespace sofa::defaulttype;

SOFA_DECL_CLASS(RayContact)

Creator<core::collision::Contact::Factory, RayContact<SphereModel> > RaySphereContactClass("ray",true);
Creator<core::collision::Contact::Factory, RayContact<TriangleModel> > RayTriangleContactClass("ray",true);
#ifndef SOFA_FLAG_SOFAPRO
Creator<core::collision::Contact::Factory, RayContact<RigidSphereModel> > RayRigidSphereContactClass("ray",true);
Creator<core::collision::Contact::Factory, RayContact<OBBModel> > RayRigidBoxContactClass("ray", true); //cast not wroking
#endif // SOFA_FLAG_SOFAPRO


BaseRayContact::BaseRayContact(CollisionModel1* model1, core::collision::Intersection* /*instersectionMethod*/)
    : model1(model1)
{
    if (model1!=NULL)
        model1->addContact(this);
}

BaseRayContact::~BaseRayContact()
{
    if (model1!=NULL)
        model1->removeContact(this);
}


} // namespace collision

} // namespace component

} // namespace sofa
