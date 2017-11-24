import java.util.Queue;
import java.util.LinkedList;

public class BFS {
    LinkedList<Integer>[] adj;

    public BFS(LinkedList<Integer>[] adj) {
        this.adj = adj;
    }

    void search(int s) {
        if (s > adj.length) {
            throw new IlleaglArgumentException();
        }
        boolean[] visited = new boolean[adj.length];

        Queue<Integer> queue = new Queue<Integer>();
        queue.add(s);

        while (!queue.isEmpty()) {
            Integer currNode = queue.poll();

            if (!visited[currNode]) {
                System.out.print(currNode + " ");
                visited[currNode] = true;
            }

            // push everything that hasn't been visited in to stack
            for (Integer neighbor : adj[currNode]) {
                if (!visited[neighbor]) {
                    queue.push(neighbor);
                }
            }

        }

    }

}
