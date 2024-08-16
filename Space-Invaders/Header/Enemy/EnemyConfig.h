#ifndef ENEMY_CONFIG_H
#define ENEMY_CONFIG_H

namespace EnemyConfig {

    enum class EnemyState {
        PATROLLING,
        ATTACKING,
        RETREATING
    };

    enum class EnemyType {
        GRUNT,
        BOSS,
        MINION
    };

    enum class EnemyDirection {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

}

#endif // ENEMY_CONFIG_H
