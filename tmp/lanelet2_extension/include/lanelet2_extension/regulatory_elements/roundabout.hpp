// Copyright 2023 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LANELET2_EXTENSION__REGULATORY_ELEMENTS__ROUNDABOUT_HPP_
#define LANELET2_EXTENSION__REGULATORY_ELEMENTS__ROUNDABOUT_HPP_

// NOLINTBEGIN(readability-identifier-naming)

#include <lanelet2_extension/regulatory_elements/Forward.hpp>

#include <lanelet2_core/primitives/Lanelet.h>

#include <memory>

namespace lanelet::autoware
{
class Roundabout : public lanelet::RegulatoryElement
{
public:
  using Ptr = std::shared_ptr<Roundabout>;
  static constexpr char RuleName[] = "roundabout";

  struct AutowareRoleNameString
  {
    static constexpr const char RoundaboutPolygon[] = "roundabout_polygon";
  };

  static Ptr make(
    Id id, const AttributeMap & attributes, const Lanelet & roundabout_lanelet,
    const Polygon3d & roundabout_area, const LineStrings3d & stop_line)
  {
    return Ptr{new Roundabout(id, attributes, roundabout_lanelet, roundabout_area, stop_line)};
  }

  /**
   * @brief get the relevant roundabout area
   * @return roundabout area
   */
  [[nodiscard]] ConstPolygon3d roundaboutArea() const;

  /**
   * @brief get the relevant roundabout line
   * @return stop line
   */
  [[nodiscard]] ConstLineStrings3d stopLines() const;

  /**
   * @brief get the relevant roundabout lanelet
   * @return lanelet
   */
  [[nodiscard]] ConstLanelet roundaboutLanelet() const;

  /**
   * @brief add a new roundabout area
   * @param primitive roundabout area to add
   */
  void addRoundaboutArea(const Polygon3d & primitive);

  /**
   * @brief remove a roundabout area
   * @param primitive the primitive
   * @return true if the roundabout area existed and was removed
   */
  bool removeRoundaboutArea(const Polygon3d & primitive);

private:
  // the following lines are required so that lanelet2 can create this object
  // when loading a map with this regulatory element
  friend class lanelet::RegisterRegulatoryElement<Roundabout>;
  Roundabout(
    Id id, const AttributeMap & attributes, const Lanelet & roundabout_lanelet,
    const Polygon3d & roundabout_area, const LineStrings3d & stop_line);
  explicit Roundabout(const lanelet::RegulatoryElementDataPtr & data);
};
static lanelet::RegisterRegulatoryElement<Roundabout> regRoundabout;

}  // namespace lanelet::autoware

// NOLINTEND(readability-identifier-naming)

#endif  // LANELET2_EXTENSION__REGULATORY_ELEMENTS__ROUNDABOUT_HPP_
