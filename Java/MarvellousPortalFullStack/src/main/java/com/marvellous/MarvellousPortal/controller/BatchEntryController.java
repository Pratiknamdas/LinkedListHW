package com.marvellous.MarvellousPortal.controller;

import com.marvellous.MarvellousPortal.Entity.BatchEntry;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/batches")
public class BatchEntryController
{
    private Map<Long, BatchEntry> batchentries = new HashMap<>();

    //HTTP : GET
    //R : Read
    //select * from batches
    @GetMapping
    public ArrayList<BatchEntry> getAll()
    {
        return new ArrayList<>(batchentries.values());
    }

    //HTTP : POST
    //C : Create
    //insert into batches values(1,'PPA',25000)
    @PostMapping
    public boolean CreateEntry(@RequestBody BatchEntry myentry)
    {
        batchentries.put(myentry.getId(),myentry);
        return true;
    }

    //HTTP : GET
    //R : Read
    //select * from where id = 1;
    @GetMapping("/id/{myid}")
    public BatchEntry getBatchEntryById(@PathVariable Long myid)
    {
        return batchentries.get(myid);
    }

    @GetMapping("/id/{myname}")
    public BatchEntry getBatchEntryByName(@PathVariable String myname)
    {
        for(BatchEntry entry : batchentries.values())
        {
            if(entry.getName().equals(myname))
            {
                return entry;
            }
        }
        return null;
    }

    //HTTP : DELETE
    // D : Delete
    // delete from batches where id = 1
    @DeleteMapping("/id/{myid}")
    public BatchEntry deleteEntryById(@PathVariable Long myid)
    {
        return batchentries.remove(myid);
    }

    // HTTP : PUT
    // U : UPDATE
    //update baatches set fees = 30000 where id = 1;
    @PutMapping("/id/{myid}")
    public BatchEntry updateEntryById(@PathVariable Long myid, BatchEntry myentry)
    {
        return batchentries.put(myid,myentry);
    }
}
