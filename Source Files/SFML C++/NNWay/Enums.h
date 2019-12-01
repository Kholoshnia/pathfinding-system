#pragma once
enum Modes { LEARN, CHECK };
enum Dimensions { TWOD, THREED };
enum LearningAlgorythms { NEAT, QL };
namespace neat { enum VisualizatoinTypes { WITHOUT, WITH }; }
namespace ql { enum VisualizatoinTypes { WITHOUT, ITERATIONS, POSITIONS }; }