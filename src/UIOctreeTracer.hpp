#ifndef UI_OCTREE_TRACER_HPP
#define UI_OCTREE_TRACER_HPP

#include "PathTracerThread.hpp"
#include "OctreeTracer.hpp"

namespace UI {
	void OctreeTracerMenuItems(const std::shared_ptr<OctreeTracer> &octree_tracer);
	void OctreeTracerRightStatus(const std::shared_ptr<OctreeTracer> &octree_tracer);
}

#endif
