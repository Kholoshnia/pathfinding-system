#pragma once
enum Modes { LEARN, CHECK };
enum Dimensions { TWOD, THREED };
enum LearningAlgorythms { NEAT, QL };
namespace neat { enum VisualizationTypes { WITHOUT, WITH }; }
namespace ql { enum VisualizationTypes { WITHOUT, ITERATIONS, STATES }; }