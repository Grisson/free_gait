/*
 * StepParameters.hpp
 *
 *  Created on: Feb 18, 2016
 *      Author: Péter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#pragma once

#include "free_gait_core/TypeDefs.hpp"
#include "free_gait_core/step/StepCompleter.hpp"

namespace free_gait {

class StepParameters
{
 public:
  StepParameters() {}
  virtual ~StepParameters() {};

  friend class StepCompleter;

  struct FootstepParameters
  {
    std::string profileType = "triangle";
    double profileHeight = 0.08;
    double averageVelocity = 0.68;
    double liftOffSpeed = 0.1;
    double touchdownSpeed = 0.2;
    double minimumDuration_ = 0.45;
  } footstepParameters;

  struct EndEffectorTargetParameters
  {
    double averageVelocity = 0.3;
    double minimumDuration_ = 0.05;
  } endEffectorTargetParameters;

  struct LegModeParameters
  {
    double duration = 0.5;
    std::string frameId = "base";
  } legModeParameters;

  struct BaseAutoParameters
  {
    double averageLinearVelocity = 0.23;
    double averageAngularVelocity = 0.33;
    double supportMargin = 0.08;
    double minimumDuration = 0.1;
    PlanarStance nominalPlanarStanceInBaseFrame;

    BaseAutoParameters()
    {
      Position2 position;
      position << 0.385, 0.25;
      nominalPlanarStanceInBaseFrame.emplace(LimbEnum::LF_LEG, position);
      nominalPlanarStanceInBaseFrame.emplace(LimbEnum::RF_LEG, Position2(Eigen::Vector2d(position(0), -position(1))));
      nominalPlanarStanceInBaseFrame.emplace(LimbEnum::LH_LEG, Position2(Eigen::Vector2d(-position(0), position(1))));
      nominalPlanarStanceInBaseFrame.emplace(LimbEnum::RH_LEG, Position2(Eigen::Vector2d(-position(0), -position(1))));
    }

  } baseAutoParameters;

  struct BaseTargetParameters
  {
    double averageLinearVelocity = 0.05;
    double averageAngularVelocity = 0.1;
    double minimumDuration = 0.7;
  } baseTargetParameters;

  struct BaseTrajectoryParameters
  {
    BaseTrajectoryParameters()
    {
    }

  } baseTrajectoryParameters;
};

} /* namespace */
