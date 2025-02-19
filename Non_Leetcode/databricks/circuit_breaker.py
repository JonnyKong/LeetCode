import random
import time


class Replica:
    def processReq(self) -> bool:
        if random.randint(0, 5) == 0:
            return False
        else:
            return True


class MockReplica(Replica):
    def processReq(self) -> bool:
        return False


class Breaker:
    def __init__(self, replica: Replica):
        self.replica = replica
        self.last_fail = 0
        self.break_period = 1

    def processReq(self) -> bool:
        if time.time() < self.last_fail + self.break_period:
            return False

        elif not self.replica.processReq():
            self.last_fail = time.time()
            return False

        return True


class Cluster:

    def __init__(self, n):
        self.replicas = [Replica() for _ in range(n)]
        self.breakers = [Breaker(r) for r in self.replicas]
        self.master_id = 0

    def processReq(self):
        success = self.breakers[self.master_id].processReq()
        if success:
            return True

        # Select new primary
        master_id = random.choice([i for i in range(len(self.breakers))
                                   if i != self.master_id])
        print(f'New master: {master_id}')
        self.master_id = master_id
        return False


def test_all():
    c = Cluster(5)
    for i in range(50):
        print(f'Processing req: {i}')
        c.processReq()
        time.sleep(0.1)


if __name__ == '__main__':
    test_all()
