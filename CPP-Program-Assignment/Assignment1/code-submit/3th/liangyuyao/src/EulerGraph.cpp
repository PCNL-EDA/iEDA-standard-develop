#include "EulerGraph.h"
#include <stdio.h>

/**
 * @brief       print Euler Circuit if it exists
 * 
 * @param       adj_list adjacency list after abstraction, 
 *                       which shows relationship in people.
 * @param       people   data in people.txt
 * @exception   
 */
void EulerGraph::printEulerCircuit(const AdjList adj_list, const std::vector<Person> people) {
    if (adj_list.size() != people.size()) {
        printf("Data miss in some files\n");
        return;
    }

    if (adj_list.size() == 0 ) {
        printf("This Graph is empty\n");
        return;
    }

    if (isExistEulerPath(adj_list) == false) {
        printf("No Eular Path\n");
        return;
    }

    // Euler Path existing does not mean Path Circuit exists
    // But once Euler Circuit exists, Path Circuit does exist.
    // And we try different starting Vertex until it stucks.
    std::vector<Node_ID> circuit;    // save Euler Circuit
    for (Node_ID vertex = 0; vertex < adj_list.size(); ++vertex) {
        if (isExistEulerCircuit(adj_list, circuit, vertex) == true) {
            // If the start-point different from the end-point, it should be Half Euler Circuit
            printf("%sEular Circuit: ", circuit[0] != circuit.back() ? "Half " : "");
            for (int v = circuit.size() - 1; v  >= 0; --v) {
                // printf("%u %s", circuit[v], v != 0 ? "-> " : "\n");  // for test
                printf("%s %s", people[circuit[v]].getName().c_str(), v != 0 ? "-> " : "\n");
            }
            return;
        }
    }

    printf("No Eular Circuit\n");
}

/**
 * @brief       
 * Note that Euler Path exist does not mean Path Circuit exist.
 * The theory base on: https://www.bilibili.com/video/BV1R4411x7x8?p=2
 * @param       adj_list adjacency list
 * @return      true when Euler Path exist, false on the countary
 * @exception   
 */
bool EulerGraph::isExistEulerPath(const AdjList adj_list) {
    std::vector<Node_ID> vec_in (adj_list.size(), 0);  // in-degree of each vertex
    std::vector<Node_ID> vec_out (adj_list.size(), 0); // out-degree of each vertex

    for (Node_ID node_out_id = 0; node_out_id < adj_list.size(); ++node_out_id) {
        vec_out[node_out_id] = adj_list[node_out_id].size();
        for (auto v_in: adj_list[node_out_id]) {
            ++vec_in[v_in];
        }
    }

    bool match = true;
    for (Node_ID v = 0; v < adj_list.size(); ++v) {
        if (vec_in[v] != vec_out[v]) {
            match = false;
            break;
        }
    }
    if (match == true) {
        // Every vertex has equal in-degree and out-degree,
        // there must exist Euler Path, and Euler Circuit as well
        return true;
    }

    Node_ID out_minus_in = 0;
    Node_ID in_minus_out = 0;
    for (Node_ID v = 0; v < adj_list.size(); ++v) {
        out_minus_in += (vec_out[v] - vec_in[v] == 1 ? 1 : 0);
        in_minus_out += (vec_in[v] - vec_out[v] == 1 ? 1 : 0);
    }

    // At most one vertex has (out-degree) - (in-degree) = 1
    // and at most one vertex has (in-degree) - (out-degree) =1
    // and all other vertices have equal in and out degree.
    // There must exist Euler Path, but not Euler Circuit.
    //
    // If not, there must not exist Euler Path and Euler Circuit.
    return out_minus_in <= 1 && in_minus_out <= 1;
}

/**
 * @brief       Check whether Euler Circuit exist by Hierholzer algorithm
 * 
 * @param       adj_list adjacency list
 * @param       circuit save the vertex order of Euler Circuit reversely
 * @param       start starting vertex to traverse Euler Circuit
 * @return      true if Euler Circuit exist, false on the contary
 * @exception   
 */
bool EulerGraph::isExistEulerCircuit(const AdjList adj_list, std::vector<Node_ID>& circuit,  const Node_ID start) {
    auto unused = adj_list; // working copy, save available edges
    std::vector<Node_ID> cur_path;  // maintain a stack to track vertex
    circuit.resize(0);
    Node_ID v_cur = start;  // current vertex
    cur_path.push_back(v_cur);

    while (!cur_path.empty()) {
        if (unused[v_cur].size()) {
            // If there is an out-edge at the current vertex,
            // move and cut it. Then update the current vertex
            Node_ID v_next = unused[v_cur].back();
            cur_path.push_back(v_next);
            unused[v_cur].pop_back();
            v_cur = v_next;
        } else {
            // If there is no out-edge at the current vertex,
            // backtrace one step to try another road that may not stuck
            // and update the current vertex
            v_cur = cur_path.back();
            if (unused[v_cur].empty()) {
                // If the last vertex that has no out-edge,
                // it means that this edge should be visited as late as possible.
                // So it acts as later vertex to visit in Euler Circuit
                circuit.push_back(v_cur);
                cur_path.pop_back();
            }
        }
    }

    // Record vertex visited according to algorithm
    std::vector<bool> visited(adj_list.size(), false);
    for (auto v: circuit) {
        visited[v] = true;
    }
    // If some vertexs are not visited, this graph must not exist Euler Circuit
    for (auto v: visited) {
        if (visited[v] == false) {
            return false;
        }
    }

    // Count edge visited according to algorithm
    Node_ID edge_num = 0;
    for (auto v_out: adj_list) {
        edge_num += v_out.size();
    }

    // If some edges are not visited, this graph must not exist Euler Circuit
    return edge_num == circuit.size() - 1;
}